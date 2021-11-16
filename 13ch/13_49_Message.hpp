#pragma once
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

    // move copy-constructor
    Message(Message&& m) noexcept: contents(std::move(m.contents)) {
        move_Folders(&m);
    }
    // 
    Message& operator=(Message &&rhs) {
        if (this != &rhs) {
            remove_from_Folders();
            contents = std::move(rhs.contents);
            move_Folders(&rhs);
        }
        return *this;
    }
    void save(Folder&);
    void remove(Folder&);
    void addFolder(Folder *);
    void remFolder(Folder *);
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
    // 移动m到本对象
    void move_Folders(Message *m) {
        // use move function of set
        folders = std::move(m->folders);
        for (auto f : folders) {
            f->remMsg(m);
            f->addMsg(this);
        }
        // 确保移动之后的m->folders是无害的
        m->folders.clear();
    }
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