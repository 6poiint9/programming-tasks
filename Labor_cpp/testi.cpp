#include <iostream>
#include <string>

using namespace std;

class AuthenticationResult {
private:
  const bool _c_is_authenticated; 
  const string _c_username;
public:
  AuthenticationResult(bool auth, string u_name = "unauthenticated_user") 
    : _c_is_authenticated{auth}, _c_username{u_name} {} 

  bool get_auth() const {
    return _c_is_authenticated;
  }

  string get_username() const {
    return _c_username; 
  }
};

class IAuthenticationProcedure {
public: 
  virtual AuthenticationResult authenticate() = 0;
  virtual ~IAuthenticationProcedure() = default; 
};

// muss sich Authentitizieren 
class Client {
    IAuthenticationProcedure* _authentication_procedure;

  public:
    void set_authentication_procedure(IAuthenticationProcedure* p) {
        _authentication_procedure = p; // dependenc injection 
    };

    void execute() {
        if (_authentication_procedure) {
            AuthenticationResult result = _authentication_procedure->authenticate();

            if (result.get_auth()) {
                cout << "Das Programm wird ausgeführt für " << result.get_username() << "." << endl;
            } else {
                cout << "Das Programm konnte nicht ausgeführt werden." << endl;
            }
        }
    }
};

// Verschiedene Authentifiketions-möglichkeiten:

class MockAuthentication : public IAuthenticationProcedure {
  public:
    AuthenticationResult authenticate() override { // const
        return AuthenticationResult(true, "Default");
    }
};

class UsernamePassword : public IAuthenticationProcedure {
    string username, password;
// username und passwort müssen gleich sein 
  public:
    AuthenticationResult authenticate() override {
        cout << "Username: " << endl;
        cin >> username;
        cout << "Password: " << endl;
        cin >> password;
        if (username == password) {
            return AuthenticationResult(true, username);
        } else {
            return AuthenticationResult(false);
        }
    }
};

class Certificate : public IAuthenticationProcedure {
  public:
    AuthenticationResult authenticate() override {
        string certificate_name;
        cout << "Zertifikatsaussteller: " << endl;
        cin >> certificate_name;
        if (certificate_name == "hs-esslingen") { // muss passen 
            return AuthenticationResult(true, "certificate.owner");
        } else {
            return AuthenticationResult(false);
        }
    }
};


int main(int argc, char* argv[]) {
    Client client;

    cout << "Authentifizierung über das Authentifizierungsverfahren Mock Authentication" << endl;
    IAuthenticationProcedure* mock_authentication = new MockAuthentication(); // objekt erstellt für MockAuthentication
    client.set_authentication_procedure(mock_authentication);
    client.execute();

    cout << "Authentifizierung über das Authentifizierungsverfahren Username Password" << endl;
    IAuthenticationProcedure* username_password = new UsernamePassword();
    client.set_authentication_procedure(username_password);
    client.execute();

    cout << "Authentifizierung über das Authentifizierungsverfahren Zertifikat" << endl;
    IAuthenticationProcedure* certificate = new Certificate();
    client.set_authentication_procedure(certificate);
    client.execute();
    return 0;
}


