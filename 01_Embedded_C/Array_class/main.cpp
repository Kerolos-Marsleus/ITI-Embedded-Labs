#include <iostream>
using namespace std;



class Array{
    private:
        static constexpr size_t DEFAULT_CAP = 4;
        int *array;
        size_t size;
        size_t capacity;
        void replace(int i, int j);
        void grow();

        public:
        Array(size_t cap = DEFAULT_CAP);
        ~Array();
        size_t get_size()const ;
        size_t get_capacity()const;
        void Display();
        void Add(int number);
        bool Average(double &result)const;
        void Insert(size_t index, int number);
        void Delete(size_t index);
        int Search(int number);
        int get(size_t index) const;
        void set(size_t index, int number);
        bool max(int &result)const ;
        bool min(int &result)const ;
        void reverse();
        long sum();
        void Merge(const Array & object);
        void shift_left(size_t n);
    };



int main(){
    Array arr(5);
    Array arr2(3);
    Array b = arr;
    b.set(0,99);
    arr.Display();
    // arr2.Add(7);
    // arr2.Add(8);
    // arr2.Add(9);

    // arr.Add(1);
    // arr.Add(2);
    // arr.Add(3);
    // arr.Add(4);

    // arr.Display();
    // arr.Add(19);
    // arr.Add(10);

    // cout << "size : " <<  arr.get_size() << endl;
    // cout << "Capacity : " << arr.get_capacity() << endl;
    // arr.Insert(2,11);
}

Array::Array(size_t cap) : array(new int[cap]), size(0),capacity(cap){}
Array::~Array(){
    delete[] array;
}

size_t Array::get_size() const {
    return size;
}

size_t Array::get_capacity() const {
    return capacity;
}

void Array::Display(){
    for(int i = 0; i < size; i++){
        cout << array[i] << endl;
    }
}

void Array::grow(){
    int *temp;
    if(capacity == 0){
        temp = new int[DEFAULT_CAP];
        capacity = DEFAULT_CAP;
    }else{
        temp = new int[capacity * 2];
        capacity *= 2;
    }
    for(int i = 0; i < size; i++){
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

void Array::Add(int number){
    if(size >= capacity){
        grow();
    }
    array[size] = number;
    size++;
}

bool Array::Average(double &result)const{
    if(size == 0){
        cout << "there are no elements in the Array" << endl;
        return false;
    }
    result = 0;
    for(size_t i = 0; i < size; i++){
        result += array[i];
    }
    result /= size;
    return true;
}

void Array::Insert(size_t index, int number){
    if(index > size){
        cout << "out of range" << endl;
        return;
    }
    if(size+1 > capacity){
        grow();
    }
    size_t curr = size;
    while(curr > index){
        array[curr] = array[curr-1];
        curr--;
    }
    array[index] = number;
    size++;
}

void Array::Delete(size_t index){
    if(index >= size){
        cout << "out of range" << endl;
        return;
    }
    while(index < size-1){
        array[index] = array[index+1];
        index++;
    }
    size--;
}

int Array::Search(int number){
    for(int i = 0; i < size; i++){
        if(array[i] == number){
            return i;
        }
    }
    return -1;
}


int Array::get(size_t index)const{
    if(index >= size){
        cout << "out of range" << endl;
        return -1;
    }
    return array[index];
}

void Array::set(size_t index, int number){
    if(index >= size){
        cout << "out of range" << endl;
        return;
    }
    array[index] = number;
}

bool Array::min(int &result)const {
    if(size == 0){
        cout << "There is no elements in the Array" << endl;
        return false;
    }
    result = array[0];
    for(size_t i = 1; i < size; i++){
        if(result > array[i]){
            result = array[i];
        }
    }
    return true;
}

bool Array::max(int &result)const{
    if(size == 0){
        cout << "There is no elements in the Array" << endl;
        return false;
    }
    result = array[0];
    for(size_t i = 1; i < size; i++){
        if(result < array[i]){
            result = array[i];
        }
    }
    return true;
}

void Array::reverse(){
    int left = 0;
    int right = size-1;
    while(left < right){
        replace(left, right);
        left++;
        right--;
    }
}

void Array::replace(int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

long Array::sum(){
    long sum = 0;
    for(int i = 0; i < size; i++){
        sum += array[i];
    }
    return sum;
}

void Array::Merge(const Array & object){
    while(capacity < size + object.get_size()){
        grow();
    }
    for(int i = 0; i < object.get_size(); i++){
        array[i+size] = object.get(i);
    }
    size += object.get_size();
}

void Array::shift_left(size_t n){
    int i = 0;
    for(i = 0; i + n < size ; i++){
        array[i] = array[i+n];
    }
    while(i < size){
        array[i] = 0;
        i++;
    }

}