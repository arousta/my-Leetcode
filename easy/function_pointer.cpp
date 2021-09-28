void f(int){
    int s;
}

int main(){
    typedef void (*myfunc)(int);
    myfunc afunc = f;
    afunc(34);
}