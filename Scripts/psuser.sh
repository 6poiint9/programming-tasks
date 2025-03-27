#!/usr/bin/env bash 

while [[ -z $1 ]] 
do 
  echo "Fehlende Eingabe: kein Benutzer eingegeben"
  exit 1 # beenden script bei falscher eingabe 
done 

# Nutzer eingegeben 
USERNAME = "$1" 

#Test auf benutzer 
if id "$USERNAME" &>/dev/null; then 
then 
 echo "Fehler nutzer existiert nicht im system"
 exit 1
fi 

# Protess des nutzers auflisten 
echo "PID COMMAND"
ps -u "$USERNAME"  -o pid,command --no-header



