main() {
    extrn a, b, putchar;
    auto p;

    b = 10;
    p = &a;
loop:
    if (p == &b)
        return;
    putchar(*p);
    p = p+1;
    goto loop;
}
a "Hello, World!\n";
b 0;
