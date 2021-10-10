
template <class E>
class ArrayList{
private:
    int len = 0;
    int index = 0;
    E* array = NULL;

public:
    ArrayList();
    ArrayList(int len);

    ~ArrayList();

    bool add(E e);

    E remove(int index);

    E get(int index);
};