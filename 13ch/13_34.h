#include<string>
#include<set>

class Folder;
class Message {
    friend class Folder;
    friend void swap(Message &, Message &);
public:
    explicit Message(const std::string &str = ""):contents(str) { };
    // copy constructor
    Message(const Message&);
    // copy-assignment operator
    Message& operator=(const Message&);
    // 析构函数
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void addFolder(Folder *);
    void remFolder(Folder *);
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};
void swap(Message &lhs, Message &rhs);

class Folder {
    friend void swap(Folder&, Folder&);
public:
    Folder() = default;
    Folder(const Folder&);
    ~Folder();
    Folder &operator=(const Folder&);

    void addMsg(Message *);
    void remMsg(Message *);
private:
    std::set<Message*> messages;
    void add_to_Message(const Folder &);
    void remove_from_Message();
};

void swap(Folder&, Folder&);