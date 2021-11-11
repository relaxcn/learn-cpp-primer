#include"13_34.h"

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::addFolder(Folder *f) {
    folders.insert(f);
}

void Message::remFolder(Folder *f) {
    folders.erase(f);
}

void Message::add_to_Folders(const Message &m) {
    for (auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m):contents(m.contents), folders(m.folders) {
    add_to_Folders(m);
}

void Message::remove_from_Folders() {
    for (auto f : folders) 
        f->remMsg(this);
}

Message::~Message() {
    remove_from_Folders();
}

Message &Message::operator=(const Message &m) {
    remove_from_Folders();
    contents = m.contents;
    folders = m.folders;
    add_to_Folders(m);
    return *this;
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

void Folder::addMsg(Message *m) {
    messages.insert(m);
}

void Folder::remMsg(Message *m) {
    messages.erase(m);
}

Folder::Folder(const Folder &f) {
    // 将此Folder对象的指针添加到f Folder对象包含的Message的对象的folders中去
    add_to_Message(f);
}

void Folder::add_to_Message(const Folder &f) {
    for (auto m : f.messages)
        m->addFolder(this);
}

// 将此Folder对象从包含它的message对象中删除
void Folder::remove_from_Message() {
    for (auto m : messages)
        m->remFolder(this);
}

Folder::~Folder() {
    remove_from_Message();
}

Folder& Folder::operator=(const Folder &f) {
    remove_from_Message();
    messages = f.messages;
    add_to_Message(f);
    return *this;
}

void swap(Folder &lhs, Folder &rhs) {
    using std::swap;
    for (auto m : lhs.messages)
        m->remFolder(&lhs);
    for (auto m : rhs.messages)
        m->remFolder(&rhs);
    swap(lhs.messages, rhs.messages);
    for (auto m : lhs.messages)
        m->addFolder(&lhs);
    for (auto m : rhs.messages)
        m->addFolder(&rhs);
}

int main()
{
    return 0;
}