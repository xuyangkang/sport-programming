#define USE_AS_HEADER

#include "./boilerplate.cc"

int main(int argc, char **argv) {
    loop(i, 10) {
        println(i);
    }

    loop(i, 3, 5) {
        println(i);
    }

    loop(i, 2, 10, 2) {
        println(i);
    }

    loopeq(i, 10) {
        println(i);
    }

    loopeq(i, 3, 5) {
        println(i);
    }

    loopeq(i, 2, 10, 2) {
        println(i);
    }
}