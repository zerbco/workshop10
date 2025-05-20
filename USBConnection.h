#ifndef USBCONNECTION_H
#define USBCONNECTION_H

#include <stack>

class USBConnection {
    private:
    int id;
    static const int MAX_PORTS = 3;
    static int port_count;
    static std:: stack<int> ids;

    USBConnection(int connection_id) : id(connection_id) {}

    public:
    ~USBConnection() {
        ids.push(id);
        port_count--;
    }

    int get_id() const {
        return id;
    }

    static USBConnection* CreateUsbConnection() {
        if (ids.empty() || port_count >= MAX_PORTS) {
            return nullptr;
        }
        int next_id = ids.top();
        ids.pop();

        port_count++;

        return new USBConnection(next_id);
    }
};

int USBConnection::port_count = 0;
std::stack<int> USBConnection::ids = [](){;
    std::stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);
    return s;
}();

#endif      // USBCONNECTION_H

