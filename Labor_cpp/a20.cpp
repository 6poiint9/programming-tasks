#include <iostream>
#include <string>

using namespace std;

class AuthenticationResult {
private:
  bool _c_is_authenticated; 
  string _c_username;
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
};

class Client {
private: 
  IAuthenticationProcedure &_authentication_procedure;

public: 
  void set_authentication_procedure(IAuthenticationProcedure *ptr) {
    _authentication_procedure = *ptr;
  }

  void execute() {
    authenticate()
  }
};


int main(int argc, char* argv[]) {
    Client client;

    cout << "Authentifizierung über das Authentifizierungsverfahren Mock Authentication" << endl;
    IAuthenticationProcedure* mock_authentication = new MockAuthentication();
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
