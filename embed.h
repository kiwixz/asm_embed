#pragma once

#ifdef __cplusplus
namespace embed
{
namespace details
{
extern "C"
{
#endif

    extern const unsigned char *embed_@name@_begin;
    extern const unsigned char *embed_@name@_end;
    extern const size_t embed_@name@_size;

#ifdef __cplusplus
}
}  // namespace embed::details

#ifndef EMBED_SPAN_
#define EMBED_SPAN_
template <typename T>
struct Span {
    Span(T* begin, T* end) : begin_{begin}, end_{end} {}
    T *begin() const noexcept { return begin_; };
    T *end() const noexcept { return end_; };

private:
    T *begin_;
    T *end_;
};
#endif

inline const Span<const unsigned char>& @name@() {
    static Span<const unsigned char> span{details::embed_@name@_begin, details::embed_@name@_end};
    return span;
}

}  // namespace embed
#endif
