#ifndef ARRAY_LIST
#define ARRAY_LIST

#include <malloc.h>
#include <cstring>

//------------声明------------
template<class E>
class ArrayList {
private:
    int len = 0;
    int index = 0;
    E *array = NULL;

public:
    ArrayList();

    ArrayList(int len);

    ArrayList(const ArrayList &list);

    ~ArrayList();

    bool add(E e);

    E remove(int index);

    E get(int index);

    int size();

private:
    void ensureCapacityInternal(int minCapacity);

    void grow(int capacity);
};

//-------------------实现--------------------
template<class E>
ArrayList<E>::ArrayList(int len) {
    if (len <= 0) {
        return;
    }
    this->len = len;
    this->array = (E *) malloc(sizeof(E) * len);
}

template<class E>
ArrayList<E>::~ArrayList() {
    if (this->array) {
        free(this->array);
        this->array = NULL;
    }
}

template<class E>
bool ArrayList<E>::add(E e) {
    ensureCapacityInternal(index + 1);
    this->array[index ++] = e;
    return true;
}

template<class E>
E ArrayList<E>::remove(int i) {
    if(i > this->len){
        return nullptr;
    }
    E oldValue = this->array[i];
    int numMoved = this->index - i - 1;
    for (int j = 0; j < numMoved; ++j) {
        array[j + i] = array[i + j + 1];
    }
    this->index -= 1;
    return oldValue;
}

template<class E>
E ArrayList<E>::get(int index) {
    return nullptr;
}

template<class E>
int ArrayList<E>::size() {
    return this->index;
}

template<class E>
void ArrayList<E>::ensureCapacityInternal(int minCapacity) {
    if (this->array == NULL) {
        minCapacity = 10;
    }
    if (minCapacity - len > 0) {
        //创建新的数组
        grow(minCapacity);
    }
}

template<class E>
void ArrayList<E>::grow(int capacity) {
    int new_len = len + (len >> 1);
    if (capacity - new_len > 0) {
        new_len = capacity;
    }
    E *new_arr = (E *) malloc(sizeof(E) * new_len);

    if (this->array) {
        //将原来的数组拷贝进来
        memcpy(new_arr, this->array, sizeof(E) * index);
        free(this->array);
    }

    this->array = new_arr;
    this->len = new_len;
}

template<class E>
ArrayList<E>::ArrayList(const ArrayList &list) {
    this->len = list.len;
    this->index = list.index;
    this->array = (E*) malloc(sizeof(E) * len);
    memcpy(this->array,list.array,sizeof(E) * len);
}

template<class E>
ArrayList<E>::ArrayList() {
    ArrayList<E>(10);
}


#endif //ARRAY_LIST