#pragma once

#ifdef __cplusplus
namespace embed
{
namespace details
{
extern "C"
{
#endif

    extern const unsigned char *embed_@NAME@_begin;
    extern const unsigned char *embed_@NAME@_end;
    extern const size_t embed_@NAME@_size;

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

inline const Span<const unsigned char>& @NAME@() {
    static Span<const unsigned char> span{details::embed_@NAME@_begin, details::embed_@NAME@_end};
    return span;
}

}  // namespace embed
#endif
