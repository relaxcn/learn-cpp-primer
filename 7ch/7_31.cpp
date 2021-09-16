class Link {
    public:
    Link *next = nullptr;
};

int
main()
{
    Link X, Y;
    X.next = &Y;
    Y.next = &X;
}