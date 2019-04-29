template <typename T = char, size_t n = 256> class Buffer{
public:
    Buffer():v(n){...}
private:
    std::vector<T> v;
}

Buffer <int, 128> a;
Buffer <> b;
