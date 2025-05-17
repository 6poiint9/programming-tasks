# Systemaufruf-Zähler - Linux-Kernelmodul Übung

## Hintergrund

Der Linux-Kernel stellt verschiedene Mechanismen zur Verfügung, um mit dem Betriebssystem zu interagieren. Systemaufrufe (System Calls) sind die primäre Schnittstelle zwischen Benutzeranwendungen und dem Kernel. Wenn ein Programm eine privilegierte Operation durchführen muss, wie z.B. das Lesen einer Datei oder die Erstellung eines Prozesses, tätigt es einen Systemaufruf.

### Systemaufrufe im Linux-Kernel

Systemaufrufe übertragen die Kontrolle vom Benutzerbereich (User Space) in den Kernelbereich (Kernel Space). Dies ermöglicht dem Kernel, die angeforderte Operation sicher auszuführen, während Benutzeranwendungen keinen direkten Zugriff auf Kernelfunktionalitäten haben. Jeder Systemaufruf hat eine eindeutige Nummer, die in einem Register (je nach Architektur) beim Aufruf übergeben wird.

### Kprobes - Kernel-Hooks

Der Linux-Kernel bietet einen Mechanismus namens "kprobes" (Kernel Probes), der es ermöglicht, dynamisch Haltepunkte (Breakpoints) und Handler an fast jeder Stelle im Kernel-Code einzufügen. Dieses nicht-intrusive Tracing-System ist für Debugging und Monitoring des Kernel-Verhaltens konzipiert, ohne dass ein Neukompilieren oder Neustarten erforderlich ist.

Kprobes ermöglichen:
- Das Anhängen von Callback-Funktionen an spezifische Kernel-Funktionen
- Das Auslösen der Callback-Funktion, wenn die angegebene Kernel-Funktion ausgeführt wird
- Das Abfangen und Überwachen von Kernel-Operationen zur Laufzeit

### Einstiegspunkte für Systemaufrufe

Um Systemaufrufe zu überwachen, müssen wir Kprobes an den Einstiegspunkten der Systemaufrufe registrieren. In verschiedenen Linux-Kerneln und auf verschiedenen Architekturen können diese Einstiegspunkte unterschiedlich sein:

- **x86_64-Architektur**:
  - `syscall_trace_enter` - Ein gebräuchlicher Einstiegspunkt für Systemaufrufe in neueren Kerneln
  - `do_syscall_64` - Spezifisch für x86_64-Architekturen

- **aarch64-Architektur (ARM64)**:
  - `syscall_trace_enter` - Kann auch auf ARM verfügbar sein
  - `invoke_syscall` - Haupteinstiegspunkt für ARM64
  - `el0_svc_common` - Alternativer ARM64-spezifischer Einstiegspunkt
  - `el0_svc_handler` - Weiterer alternativer ARM64-spezifischer Einstiegspunkt

Da die Verfügbarkeit dieser Einstiegspunkte je nach Kernel-Version und Architektur variieren kann, ist es eine gute Praxis, mehrere mögliche Einstiegspunkte zu definieren und sie nacheinander zu versuchen. In Ihrem Modul sollten Sie einen Ansatz implementieren, der verschiedene Einstiegspunkte versucht, bis einer erfolgreich registriert wird:

```c
// Definition möglicher Einstiegspunkte
#if defined(__x86_64__)
static const char *possible_syscall_entries[] = {
    "syscall_trace_enter",
    "do_syscall_64",
    NULL
};
#elif defined(__aarch64__)
static const char *possible_syscall_entries[] = {
    "syscall_trace_enter",
    "invoke_syscall",
    NULL
};
#else
static const char *possible_syscall_entries[] = {
    "syscall_trace_enter",
    NULL
};
#endif

// Im Initialisierungscode:
bool probe_registered = false;
for (i = 0; possible_syscall_entries[i] != NULL; i++) {
    kp.symbol_name = possible_syscall_entries[i];
    ret = register_kprobe(&kp);
    if (ret == 0) {
        // Erfolgreich registriert
        probe_registered = true;
        break;
    }
}
```

Diese Methode erhöht die Portabilität Ihres Moduls auf verschiedenen Architekturen und Kernel-Versionen.

### Das /proc-Dateisystem

Das /proc-Dateisystem ist ein virtuelles Dateisystem, das Kernel-Informationen im Userspace zugänglich macht. Es bietet eine einfache Schnittstelle zur Anzeige von Kernel-Daten über normale Dateioperationen. In unserem Modul erstellen wir einen Eintrag unter `/proc/syscall_counter`, der die Anzahl der Systemaufrufe anzeigt.

## Aufgabenbeschreibung

In dieser Übung entwickeln Sie ein Linux-Kernelmodul, das:
1. Systemaufrufe mittels Kprobes überwacht
2. Die Anzahl jedes Systemaufrufs zählt
3. Einen `/proc/syscall_counter`-Eintrag erstellt, der die Zählungen anzeigt
4. Ressourcen ordnungsgemäß initialisiert und bereinigt

## Vorbereitung der Entwicklungsumgebung

Bevor Sie mit der Entwicklung beginnen können, muss Ihre Kernel-Umgebung korrekt vorbereitet sein:

### Kernel-Header installieren

```bash
sudo apt-get update
sudo apt-get install linux-headers-$(uname -r)
```

### Kernel-Quelltree vorbereiten (falls notwendig)

Wenn Sie den vollständigen Kernel-Quellcode verwenden und Fehlermeldungen wie "Kernel configuration is invalid" erhalten:

```bash
cd /usr/src/linux-$(uname -r)
sudo make oldconfig
sudo make prepare
```

Ohne diese Vorbereitung könnten Sie Fehlermeldungen erhalten wie:
```
ERROR: Kernel configuration is invalid.
include/generated/autoconf.h or include/config/auto.conf are missing.
Run 'make oldconfig && make prepare' on kernel src to fix it.
```

### Benötigte Pakete installieren

```bash
sudo apt-get install build-essential make gcc
```

## Arbeitsschritte

### Schritt 1: Verstehen des Codes
1. Sehen Sie sich den bereitgestellten Code in `mod_sycall_counter.c` an
2. Identifizieren Sie die Hauptkomponenten:
   - Modul-Initialisierung und -Bereinigung
   - Kprobe-Registrierung
   - /proc-Schnittstelle
   - Zählmechanismus für Systemaufrufe

### Schritt 2: Implementierung
1. Vervollständigen Sie die TODOs im Code:
   - Definieren Sie eine Datenstruktur zum Speichern der Systemaufrufzählungen
   - Fügen Sie einen Synchronisationsmechanismus hinzu (z.B. spinlock)
   - Extrahieren Sie die Systemaufrufnummer in der Kprobe-Handler-Funktion
   - Implementieren Sie die Anzeige der Zählungen im /proc-Eintrag

#### Kprobe-Handler implementieren

Die Kernelfunktion zum Registrieren eines Kprobes ist `register_kprobe()`. Für den Handler müssen Sie die Systemaufrufnummer aus den Registern extrahieren, wobei dies architekturabhängig ist:

```c
static int handler_pre(struct kprobe *p, struct pt_regs *regs)
{
    unsigned long syscall_nr;
    
    // Architekturspezifischer Code
    #if defined(__x86_64__)
        // x86_64-Architektur
        #if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 17, 0)
            // Bei neueren Kernel-Versionen (4.17+)
            syscall_nr = regs->orig_ax;
        #else
            // Bei älteren Kernel-Versionen
            syscall_nr = regs->ax;
        #endif
    #elif defined(__aarch64__)
        // ARM64-Architektur
        // Bei verschiedenen ARM64-Implementierungen kann der Register-Index variieren
        syscall_nr = regs->regs[1]; // Hauptsächlich verwendet in neueren Kerneln
        // Alternative: syscall_nr = regs->regs[8]; // In manchen ARM64-Implementierungen
    #else
        #error "Architektur nicht unterstützt"
    #endif
    
    // Stellen Sie sicher, dass die Syscall-Nummer in unserem Bereich liegt
    if (syscall_nr < MAX_SYSCALLS) {
        // TODO: Zähler inkrementieren (mit Synchronisation)
    }
    
    return 0;
}
```

#### Systemaufrufnamen definieren

Um die Lesbarkeit der Ausgabe zu verbessern, können Sie die Namen der Systemaufrufe automatisch aus den Kernel-Quellen generieren. Dafür steht das Skript `gen_syscall_names.sh` zur Verfügung, das eine Header-Datei mit den Systemaufrufnamen erstellt.

Das Skript analysiert die Systemaufruf-Tabelle des Linux-Kernels für Ihre spezifische Architektur (x86_64 oder aarch64) und generiert eine Header-Datei `syscall_names.h` mit einem Array, das die Systemaufrufnummern ihren Namen zuordnet.

Verwendung des Skripts:
Das Skript wird automatisch beim Kompilieren des Moduls mittels `make` ausgeführt. Sie müssen es nicht manuell ausführen. Das Kernel Module .c Template inkludiert die generierte Header-Datei. Möchten Sie die Header-Datei manuell generieren, können Sie das Skript ausführen:
```bash
# Das Skript benötigt den Pfad zum Linux-Kernel-Quellcode
./gen_syscall_names.sh /pfad/zum/linux-kernel
```

Das generierte `syscall_names.h` enthält ein Array der Form:
```c
static const char * const syscall_names[] = {
    [0] = "read",
    [1] = "write",
    [2] = "open",
    // ... weitere Systemaufrufe ...
};
```

Um die generierten Namen in Ihrem Modul zu verwenden:
1. Fügen Sie die Header-Datei in Ihr Modul ein:
   ```c
   #include "syscall_names.h"
   ```
2. Aktivieren Sie die Namensanzeige in Ihrem Code:
   ```c
   #define WANT_SYSCALL_NAMES
   ```
3. Verwenden Sie das Array in der Ausgabefunktion:
   ```c
   #ifdef WANT_SYSCALL_NAMES
       const char *name = "unbekannt";
       if (i < sizeof(syscall_names)/sizeof(syscall_names[0]) && syscall_names[i]) {
           name = syscall_names[i];
       }
       seq_printf(m, "%-4d %-8lu %s\n", i, syscall_count[i], name);
   #else
       seq_printf(m, "%d: %lu\n", i, syscall_count[i]);
   #endif
   ```

Das Skript berücksichtigt architekturspezifische Unterschiede und generiert die korrekten Namen basierend auf der Systemaufruf-Tabelle Ihrer Architektur. Es ist besonders nützlich, da es:
- Automatisch die korrekten Systemaufrufnamen für Ihre Architektur generiert
- Doppelte Einträge in der Systemaufruf-Tabelle korrekt behandelt
- Eine konsistente Formatierung der Ausgabe gewährleistet








# -----------------------------------------------------------------------------------------------
#### Erstellen eines /proc-Eintrags ------------------------------- 

Um einen /proc-Eintrag zu erstellen, verwenden Sie `proc_create()`. Implementieren Sie die Funktion zur Anzeige der Daten mit `seq_file`-Operationen:

```c
static int mod_sycall_counter_show(struct seq_file *m, void *v)
{
    int i;
    
    seq_printf(m, "Systemaufruf-Zählungen:\n");
    seq_printf(m, "----------------------\n");
    
    for (i = 0; i < MAX_SYSCALLS; i++) {
        if (syscall_count[i] > 0) {
            // TODO: Zeige Systemaufrufnummer, Name und Anzahl an
            seq_printf(m, "%d: %lu\n", i, syscall_count[i]);
            // // Systemaufrufnamen (optional)
            // #ifdef WANT_SYSCALL_NAMES
            //     const char *name = "unbekannt";
            //     if (i < sizeof(syscall_names)/sizeof(syscall_names[0]) && syscall_names[i]) {
            //         name = syscall_names[i];
            //     }
            //     seq_printf(m, "%-4d %-8lu %s\n", i, syscall_count[i], name);
            // #else
            //     seq_printf(m, "%d: %lu\n", i, syscall_count[i]);
            // #endif
        }
    }
    
    return 0;
}
```

# --------------------------------------------------------------------------------------------------------------------

### Schritt 3: Testen
1. Kompilieren Sie das Modul mit `make`
2. Laden Sie das Modul mit `sudo insmod mod_sycall_counter.ko`
3. Überprüfen Sie die Kernel-Logmeldungen mit `dmesg | tail`
(4. Zeigen Sie die Systemaufrufzählungen mit `cat /proc/syscall_counter` an )
5. Führen Sie einige Befehle aus und beobachten Sie, wie sich die Zählungen ändern
6. Entladen Sie das Modul mit `sudo rmmod mod_sycall_counter`

# -------------------------------------------------------------------------------------------------------------------- 

### Problembehandlung beim Kompilieren

Falls Sie Probleme beim Kompilieren des Moduls haben:

1. **Überprüfen Sie die Vorbereitung der Kernel-Umgebung** (wie oben beschrieben)
2. **Verbosity erhöhen**, um detailliertere Fehlerinformationen zu erhalten:
   ```bash
   make V=1
   ```
3. **Prüfen Sie, ob die Quelldateien gefunden werden**:
   ```bash
   make check
   ```
4. **Fehlermeldungen analysieren**:
   - Bei "No rule to make target": Stellen Sie sicher, dass die Quelldateien im richtigen Verzeichnis liegen
   - Bei "Symbol not found": Überprüfen Sie die Kernelversion und die Verfügbarkeit der Funktionen

### Schritt 4: Erweiterte Aufgaben (Optional)
1. Fügen Sie eine Reset-Funktion hinzu, um die Zähler zurückzusetzen
2. Verfolgen Sie zusätzliche Informationen wie die Aufrufzeit
3. Erstellen Sie ein Userspace-Tool zur Visualisierung der Daten

## Das Test-Skript (test_mod_syscall_counter.sh)

Das bereitgestellte Bash-Skript `test_mod_syscall_counter.sh` testet das Kernel-Modul:

1. Es prüft, ob das Modul bereits geladen ist und entlädt es gegebenenfalls
2. Es lädt das Modul neu
3. Es zeigt die anfänglichen Systemaufrufzählungen an
4. Es führt verschiedene Befehle aus, um Systemaufrufe zu generieren:
   - Dateisystemoperationen (ls)
   - Prozessinformationen abrufen (ps)
   - Datei-I/O-Operationen (Erstellen, Lesen, Löschen einer Datei)
5. Es zeigt die aktualisierten Zählungen nach jeder Operation an
6. Es entlädt das Modul am Ende

Das Skript soll demonstrieren, dass verschiedene Befehle unterschiedliche Systemaufrufe tätigen. Nach der Ausführung des Skripts sollten Sie in der `/proc/syscall_counter`-Ausgabe beobachten können, dass Systemaufrufe wie `read`, `write`, `open`, `close`, `stat` und andere mehrfach aufgerufen wurden.

## Kompilieren und Laden des Moduls

```bash
# Modul kompilieren
make

# Bei Problemen mit mehr Details kompilieren
make verbose

# Umgebung überprüfen
make check

# Modul laden
sudo insmod mod_sycall_counter.ko

# Modul-Ausgabe anzeigen
cat /proc/syscall_counter

# Modul entladen
sudo rmmod mod_sycall_counter
```

## Hinweise
- Stellen Sie sicher, dass Ihre Kernel-Header auf Ihrem System installiert sind
- Dieses Modul wurde auf Linux-Kernel 5.10+ getestet
- Für verschiedene Kernel-Versionen können Anpassungen erforderlich sein
- Compiler-Warnungen bezüglich unterschiedlicher Compiler-Versionen können in der Regel ignoriert werden

## Ressourcen
- [Linux Kernel Module Programming Guide](https://sysprog21.github.io/lkmpg/) - Eine hervorragende Ressource für die Entwicklung von Kernel-Modulen
  - Kapitel 7 behandelt speziell das [/proc-Dateisystem](https://sysprog21.github.io/lkmpg/ch07.html)
  - Kapitel 11 und 12 behandeln Synchronisationsmechanismen, die für diese Übung benötigt werden
- [Kprobes-Dokumentation](https://www.kernel.org/doc/html/latest/trace/kprobes.html)
- [Linux-Systemaufruf-Tabellenreferenz](https://filippo.io/linux-syscall-table/)
- [Linux-Kernel-Dokumentation zu /proc](https://www.kernel.org/doc/html/latest/filesystems/proc.html) 
