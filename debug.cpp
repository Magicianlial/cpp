//debug
template<class...Args>
void debug(Args... args) {
    auto tmp = {(cout << args << ' ', 0)...};
    cout << endl;
}