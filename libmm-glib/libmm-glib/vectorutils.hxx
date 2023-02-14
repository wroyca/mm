#ifndef _GLIBMM_VECTORUTILS_H
#define _GLIBMM_VECTORUTILS_H

#include <cstddef>
#include <libmm-glib/containerhandle_shared.hxx>
#include <libmm-glib/mm-glibconfig.hxx>
#include <vector>

namespace Glib
{

  namespace Container_Helpers
  {

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    template <class T>
    inline auto
    compute_array_size2 (const T* array) -> std::size_t
    {
      if (array)
      {
        const T* pend (array);

        while (*pend)
        {
          ++pend;
        }
        return (pend - array);
      }

      return 0;
    }

    template <class Tr>
    auto
    create_array (
        typename std::vector<typename Tr::CppType>::const_iterator pbegin,
        std::size_t size) -> typename Tr::CType*
    {
      using CType = typename Tr::CType;

      CType* const array (
          static_cast<CType*> (g_malloc ((size + 1) * sizeof (CType))));
      CType* const array_end (array + size);

      for (CType* pdest (array); pdest != array_end; ++pdest)
      {
        *pdest = Tr::to_c_type (*&*pbegin);
        ++pbegin;
      }
      *array_end = CType ();

      return array;
    }

    GLIBMM_API
    auto
    create_bool_array (std::vector<bool>::const_iterator pbegin,
                       std::size_t size) -> gboolean*;

    template <class Tr>
    auto
    create_glist (
        const typename std::vector<typename Tr::CppType>::const_iterator pbegin,
        typename std::vector<typename Tr::CppType>::const_iterator pend)
        -> GList*
    {
      GList* head (nullptr);

      while (pend != pbegin)
      {
        const void* const item (Tr::to_c_type (*&*--pend));
        head = g_list_prepend (head, const_cast<void*> (item));
      }

      return head;
    }

    template <class Tr>
    auto
    create_gslist (
        const typename std::vector<typename Tr::CppType>::const_iterator pbegin,
        typename std::vector<typename Tr::CppType>::const_iterator pend)
        -> GSList*
    {
      GSList* head (nullptr);

      while (pend != pbegin)
      {
        const void* const item (Tr::to_c_type (*&*--pend));
        head = g_slist_prepend (head, const_cast<void*> (item));
      }

      return head;
    }

#endif

    template <class Tr>
    class ArrayIterator
    {
    public:
      using CppType = typename Tr::CppType;
      using CType = typename Tr::CType;

      using iterator_category = std::random_access_iterator_tag;
      using value_type = CppType;
      using difference_type = std::ptrdiff_t;
      using reference = value_type;
      using pointer = void;

      explicit inline ArrayIterator (const CType* pos);

      inline auto
      operator* () const -> value_type;
      inline auto
      operator[] (difference_type offset) const -> value_type;

      inline auto
      operator++ () -> ArrayIterator<Tr>&;
      inline auto
      operator++ (int) -> const ArrayIterator<Tr>;

      inline auto
      operator+= (difference_type rhs) -> ArrayIterator<Tr>&;
      inline auto
      operator-= (difference_type rhs) -> ArrayIterator<Tr>&;
      inline auto
      operator+ (difference_type rhs) const -> const ArrayIterator<Tr>;
      inline auto
      operator- (difference_type rhs) const -> const ArrayIterator<Tr>;
      inline auto
      operator- (const ArrayIterator<Tr>& rhs) const -> difference_type;

      inline auto
      operator== (const ArrayIterator<Tr>& rhs) const -> bool;
      inline auto
      operator!= (const ArrayIterator<Tr>& rhs) const -> bool;
      inline auto
      operator<(const ArrayIterator<Tr>& rhs) const -> bool;
      inline auto
      operator> (const ArrayIterator<Tr>& rhs) const -> bool;
      inline auto
      operator<= (const ArrayIterator<Tr>& rhs) const -> bool;
      inline auto
      operator>= (const ArrayIterator<Tr>& rhs) const -> bool;

    private:
      const CType* pos_;
    };

    template <class Tr>
    class ListIterator
    {
    public:
      using CppType = typename Tr::CppType;
      using CType = typename Tr::CType;

      using iterator_category = std::forward_iterator_tag;
      using value_type = CppType;
      using difference_type = std::ptrdiff_t;
      using reference = value_type;
      using pointer = void;

      explicit inline ListIterator (const GList* node);

      inline auto
      operator* () const -> value_type;
      inline auto
      operator++ () -> ListIterator<Tr>&;
      inline auto
      operator++ (int) -> const ListIterator<Tr>;

      inline auto
      operator== (const ListIterator<Tr>& rhs) const -> bool;
      inline auto
      operator!= (const ListIterator<Tr>& rhs) const -> bool;

    private:
      const GList* node_;
    };

    template <class Tr>
    class SListIterator
    {
    public:
      using CppType = typename Tr::CppType;
      using CType = typename Tr::CType;

      using iterator_category = std::forward_iterator_tag;
      using value_type = CppType;
      using difference_type = std::ptrdiff_t;
      using reference = value_type;
      using pointer = void;

      explicit inline SListIterator (const GSList* node);

      inline auto
      operator* () const -> value_type;
      inline auto
      operator++ () -> SListIterator<Tr>&;
      inline auto
      operator++ (int) -> const SListIterator<Tr>;

      inline auto
      operator== (const SListIterator<Tr>& rhs) const -> bool;
      inline auto
      operator!= (const SListIterator<Tr>& rhs) const -> bool;

    private:
      const GSList* node_;
    };

    template <typename Tr>
    class ArrayKeeper
    {
    public:
      using CppType = typename Tr::CppType;
      using CType = typename Tr::CType;

      explicit inline ArrayKeeper (const CType* array,
                                   std::size_t array_size,
                                   Glib::OwnershipType ownership);
      inline ArrayKeeper (const ArrayKeeper& keeper);
      ~ArrayKeeper () noexcept;

      inline auto
      data () const -> CType*;

    private:
      CType* array_;
      std::size_t array_size_;
      mutable Glib::OwnershipType ownership_;
    };

    template <typename Tr>
    class GListKeeper
    {
    public:
      using CppType = typename Tr::CppType;
      using CType = typename Tr::CType;

      explicit inline GListKeeper (const GList* glist,
                                   Glib::OwnershipType ownership);
      inline GListKeeper (const GListKeeper& keeper);
      ~GListKeeper () noexcept;

      inline auto
      data () const -> GList*;

    private:
      GList* glist_;
      mutable Glib::OwnershipType ownership_;
    };

    template <typename Tr>
    class GSListKeeper
    {
    public:
      using CppType = typename Tr::CppType;
      using CType = typename Tr::CType;

      explicit inline GSListKeeper (const GSList* gslist,
                                    Glib::OwnershipType ownership);
      inline GSListKeeper (const GSListKeeper& keeper);
      ~GSListKeeper () noexcept;

      inline auto
      data () const -> GSList*;

    private:
      GSList* gslist_;
      mutable Glib::OwnershipType ownership_;
    };

  } // namespace Container_Helpers

  template <typename T, typename Tr = Glib::Container_Helpers::TypeTraits<T>>
  class ArrayHandler
  {
  public:
    using CType = typename Tr::CType;
    using CppType = T;
    using VectorType = std::vector<CppType>;
    using ArrayKeeperType = typename Glib::Container_Helpers::ArrayKeeper<Tr>;
    using ArrayIteratorType =
        typename Glib::Container_Helpers::ArrayIterator<Tr>;

    static auto
    array_to_vector (const CType* array,
                     std::size_t array_size,
                     Glib::OwnershipType ownership) -> VectorType;
    static auto
    array_to_vector (const CType* array, Glib::OwnershipType ownership)
        -> VectorType;
    static auto
    vector_to_array (const VectorType& vector) -> ArrayKeeperType;
  };

  template <>
  class GLIBMM_API ArrayHandler<bool>
  {
  public:
    using CType = gboolean;
    using CppType = bool;
    using VectorType = std::vector<bool>;
    typedef Glib::Container_Helpers::ArrayKeeper<
        Glib::Container_Helpers::TypeTraits<bool>>
        ArrayKeeperType;
    typedef Glib::Container_Helpers::ArrayIterator<
        Glib::Container_Helpers::TypeTraits<bool>>
        ArrayIteratorType;

    static auto
    array_to_vector (const CType* array,
                     std::size_t array_size,
                     Glib::OwnershipType ownership) -> VectorType;
    static auto
    array_to_vector (const CType* array, Glib::OwnershipType ownership)
        -> VectorType;
    static auto
    vector_to_array (const VectorType& vector) -> ArrayKeeperType;
  };

  template <typename T, typename Tr = Glib::Container_Helpers::TypeTraits<T>>
  class ListHandler
  {
  public:
    using CType = typename Tr::CType;
    using CppType = T;
    using VectorType = std::vector<CppType>;
    using GListKeeperType = typename Glib::Container_Helpers::GListKeeper<Tr>;
    using ListIteratorType = typename Glib::Container_Helpers::ListIterator<Tr>;

    static auto
    list_to_vector (GList* glist, Glib::OwnershipType ownership) -> VectorType;
    static auto
    vector_to_list (const VectorType& vector) -> GListKeeperType;
  };

  template <typename T, typename Tr = Glib::Container_Helpers::TypeTraits<T>>
  class SListHandler
  {
  public:
    using CType = typename Tr::CType;
    using CppType = T;
    using VectorType = std::vector<CppType>;
    using GSListKeeperType = typename Glib::Container_Helpers::GSListKeeper<Tr>;
    using SListIteratorType =
        typename Glib::Container_Helpers::SListIterator<Tr>;

    static auto
    slist_to_vector (GSList* gslist, Glib::OwnershipType ownership)
        -> VectorType;
    static auto
    vector_to_slist (const VectorType& vector) -> GSListKeeperType;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  namespace Container_Helpers
  {

    template <class Tr>
    inline ArrayIterator<Tr>::ArrayIterator (const CType* pos)
      : pos_ (pos)
    {
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator* () const ->
        typename ArrayIterator<Tr>::value_type
    {
      return Tr::to_cpp_type (*pos_);
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator[] (difference_type offset) const ->
        typename ArrayIterator<Tr>::value_type
    {
      return Tr::to_cpp_type (pos_[offset]);
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator++ () -> ArrayIterator<Tr>&
    {
      ++pos_;
      return *this;
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator++ (int) -> const ArrayIterator<Tr>
    {
      return ArrayIterator<Tr> (pos_++);
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator+= (
        typename ArrayIterator<Tr>::difference_type rhs) -> ArrayIterator<Tr>&
    {
      pos_ += rhs;
      return *this;
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator-= (
        typename ArrayIterator<Tr>::difference_type rhs) -> ArrayIterator<Tr>&
    {
      pos_ -= rhs;
      return *this;
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator+ (
        typename ArrayIterator<Tr>::difference_type rhs) const
        -> const ArrayIterator<Tr>
    {
      return ArrayIterator<Tr> (pos_ + rhs);
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator- (
        typename ArrayIterator<Tr>::difference_type rhs) const
        -> const ArrayIterator<Tr>
    {
      return ArrayIterator<Tr> (pos_ - rhs);
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator- (const ArrayIterator<Tr>& rhs) const ->
        typename ArrayIterator<Tr>::difference_type
    {
      return (pos_ - rhs.pos_);
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator== (const ArrayIterator<Tr>& rhs) const -> bool
    {
      return (pos_ == rhs.pos_);
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator!= (const ArrayIterator<Tr>& rhs) const -> bool
    {
      return (pos_ != rhs.pos_);
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator<(const ArrayIterator<Tr>& rhs) const -> bool
    {
      return (pos_ < rhs.pos_);
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator> (const ArrayIterator<Tr>& rhs) const -> bool
    {
      return (pos_ > rhs.pos_);
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator<= (const ArrayIterator<Tr>& rhs) const -> bool
    {
      return (pos_ <= rhs.pos_);
    }

    template <class Tr>
    inline auto
    ArrayIterator<Tr>::operator>= (const ArrayIterator<Tr>& rhs) const -> bool
    {
      return (pos_ >= rhs.pos_);
    }

    template <class Tr>
    inline ListIterator<Tr>::ListIterator (const GList* node)
      : node_ (node)
    {
    }

    template <class Tr>
    inline auto
    ListIterator<Tr>::operator* () const ->
        typename ListIterator<Tr>::value_type
    {
      return Tr::to_cpp_type (
          static_cast<typename Tr::CTypeNonConst> (node_->data));
    }

    template <class Tr>
    inline auto
    ListIterator<Tr>::operator++ () -> ListIterator<Tr>&
    {
      node_ = node_->next;
      return *this;
    }

    template <class Tr>
    inline auto
    ListIterator<Tr>::operator++ (int) -> const ListIterator<Tr>
    {
      const ListIterator<Tr> tmp (*this);
      node_ = node_->next;
      return tmp;
    }

    template <class Tr>
    inline auto
    ListIterator<Tr>::operator== (const ListIterator<Tr>& rhs) const -> bool
    {
      return (node_ == rhs.node_);
    }

    template <class Tr>
    inline auto
    ListIterator<Tr>::operator!= (const ListIterator<Tr>& rhs) const -> bool
    {
      return (node_ != rhs.node_);
    }

    template <class Tr>
    inline SListIterator<Tr>::SListIterator (const GSList* node)
      : node_ (node)
    {
    }

    template <class Tr>
    inline auto
    SListIterator<Tr>::operator* () const ->
        typename SListIterator<Tr>::value_type
    {
      return Tr::to_cpp_type (
          static_cast<typename Tr::CTypeNonConst> (node_->data));
    }

    template <class Tr>
    inline auto
    SListIterator<Tr>::operator++ () -> SListIterator<Tr>&
    {
      node_ = node_->next;
      return *this;
    }

    template <class Tr>
    inline auto
    SListIterator<Tr>::operator++ (int) -> const SListIterator<Tr>
    {
      const ListIterator<Tr> tmp (*this);
      node_ = node_->next;
      return tmp;
    }

    template <class Tr>
    inline auto
    SListIterator<Tr>::operator== (const SListIterator<Tr>& rhs) const -> bool
    {
      return (node_ == rhs.node_);
    }

    template <class Tr>
    inline auto
    SListIterator<Tr>::operator!= (const SListIterator<Tr>& rhs) const -> bool
    {
      return (node_ != rhs.node_);
    }

    template <typename Tr>
    inline ArrayKeeper<Tr>::ArrayKeeper (const CType* array,
                                         std::size_t array_size,
                                         Glib::OwnershipType ownership)
      : array_ (const_cast<CType*> (array)),
        array_size_ (array_size),
        ownership_ (ownership)
    {
    }

    template <typename Tr>
    inline ArrayKeeper<Tr>::ArrayKeeper (const ArrayKeeper& keeper)
      : array_ (keeper.array_),
        array_size_ (keeper.array_size_),
        ownership_ (keeper.ownership_)
    {
      keeper.ownership_ = Glib::OWNERSHIP_NONE;
    }

    template <typename Tr>
    ArrayKeeper<Tr>::~ArrayKeeper () noexcept
    {
      if (array_ && ownership_ != Glib::OWNERSHIP_NONE)
      {
        if (ownership_ != Glib::OWNERSHIP_SHALLOW)
        {
          const CType* const array_end (array_ + array_size_);

          for (const CType* p (array_); p != array_end; ++p)
          {
            Tr::release_c_type (*p);
          }
        }
        g_free (const_cast<CType*> (array_));
      }
    }

    template <typename Tr>
    inline auto
    ArrayKeeper<Tr>::data () const -> typename Tr::CType*
    {
      return array_;
    }

    template <typename Tr>
    inline GListKeeper<Tr>::GListKeeper (const GList* glist,
                                         Glib::OwnershipType ownership)
      : glist_ (const_cast<GList*> (glist)),
        ownership_ (ownership)
    {
    }

    template <typename Tr>
    inline GListKeeper<Tr>::GListKeeper (const GListKeeper& keeper)
      : glist_ (keeper.glist_),
        ownership_ (keeper.ownership_)
    {
      keeper.ownership_ = Glib::OWNERSHIP_NONE;
    }

    template <typename Tr>
    GListKeeper<Tr>::~GListKeeper () noexcept
    {
      using CTypeNonConst = typename Tr::CTypeNonConst;

      if (glist_ && ownership_ != Glib::OWNERSHIP_NONE)
      {
        if (ownership_ != Glib::OWNERSHIP_SHALLOW)
        {
          for (GList* node = glist_; node; node = node->next)
          {
            Tr::release_c_type (static_cast<CTypeNonConst> (node->data));
          }
        }
        g_list_free (glist_);
      }
    }

    template <typename Tr>
    inline auto
    GListKeeper<Tr>::data () const -> GList*
    {
      return glist_;
    }

    template <typename Tr>
    inline GSListKeeper<Tr>::GSListKeeper (const GSList* gslist,
                                           Glib::OwnershipType ownership)
      : gslist_ (const_cast<GSList*> (gslist)),
        ownership_ (ownership)
    {
    }

    template <typename Tr>
    inline GSListKeeper<Tr>::GSListKeeper (const GSListKeeper& keeper)
      : gslist_ (keeper.gslist_),
        ownership_ (keeper.ownership_)
    {
      keeper.ownership_ = Glib::OWNERSHIP_NONE;
    }

    template <typename Tr>
    GSListKeeper<Tr>::~GSListKeeper () noexcept
    {
      using CTypeNonConst = typename Tr::CTypeNonConst;
      if (gslist_ && ownership_ != Glib::OWNERSHIP_NONE)
      {
        if (ownership_ != Glib::OWNERSHIP_SHALLOW)
        {
          for (GSList* node = gslist_; node; node = node->next)
          {
            Tr::release_c_type (static_cast<CTypeNonConst> (node->data));
          }
        }
        g_slist_free (gslist_);
      }
    }

    template <typename Tr>
    inline auto
    GSListKeeper<Tr>::data () const -> GSList*
    {
      return gslist_;
    }

  } // namespace Container_Helpers

  template <typename T, class Tr>
  auto
  ArrayHandler<T, Tr>::array_to_vector (const CType* array,
                                        std::size_t array_size,
                                        Glib::OwnershipType ownership) ->
      typename ArrayHandler<T, Tr>::VectorType
  {
    if (array)
    {
      ArrayKeeperType keeper (array, array_size, ownership);
  #ifdef GLIBMM_HAVE_TEMPLATE_SEQUENCE_CTORS
      return VectorType (ArrayIteratorType (array),
                         ArrayIteratorType (array + array_size));
  #else
      VectorType temp;
      temp.reserve (array_size);
      Glib::Container_Helpers::fill_container (
          temp,
          ArrayIteratorType (array),
          ArrayIteratorType (array + array_size));
      return temp;
  #endif
    }
    return VectorType ();
  }

  template <typename T, class Tr>
  auto
  ArrayHandler<T, Tr>::array_to_vector (const CType* array,
                                        Glib::OwnershipType ownership) ->
      typename ArrayHandler<T, Tr>::VectorType
  {
    return array_to_vector (
        array,
        Glib::Container_Helpers::compute_array_size2 (array),
        ownership);
  }

  template <typename T, class Tr>
  auto
  ArrayHandler<T, Tr>::vector_to_array (const VectorType& vector) ->
      typename ArrayHandler<T, Tr>::ArrayKeeperType
  {
    return ArrayKeeperType (
        Glib::Container_Helpers::create_array<Tr> (vector.begin (),
                                                   vector.size ()),
        vector.size (),
        Glib::OWNERSHIP_SHALLOW);
  }

  template <typename T, class Tr>
  auto
  ListHandler<T, Tr>::list_to_vector (GList* glist,
                                      Glib::OwnershipType ownership) ->
      typename ListHandler<T, Tr>::VectorType
  {
    GListKeeperType keeper (glist, ownership);
  #ifdef GLIBMM_HAVE_TEMPLATE_SEQUENCE_CTORS
    return VectorType (ListIteratorType (glist), ListIteratorType (nullptr));
  #else
    VectorType temp;
    temp.reserve (g_list_length (glist));
    Glib::Container_Helpers::fill_container (temp,
                                             ListIteratorType (glist),
                                             ListIteratorType (nullptr));
    return temp;
  #endif
  }

  template <typename T, class Tr>
  auto
  ListHandler<T, Tr>::vector_to_list (const VectorType& vector) ->
      typename ListHandler<T, Tr>::GListKeeperType
  {
    return GListKeeperType (
        Glib::Container_Helpers::create_glist<Tr> (vector.begin (),
                                                   vector.end ()),
        Glib::OWNERSHIP_SHALLOW);
  }

  template <typename T, class Tr>
  auto
  SListHandler<T, Tr>::slist_to_vector (GSList* gslist,
                                        Glib::OwnershipType ownership) ->
      typename SListHandler<T, Tr>::VectorType
  {
    GSListKeeperType keeper (gslist, ownership);
  #ifdef GLIBMM_HAVE_TEMPLATE_SEQUENCE_CTORS
    return VectorType (SListIteratorType (gslist), SListIteratorType (nullptr));
  #else
    VectorType temp;
    temp.reserve (g_slist_length (gslist));
    Glib::Container_Helpers::fill_container (temp,
                                             SListIteratorType (gslist),
                                             SListIteratorType (nullptr));
    return temp;
  #endif
  }

  template <typename T, class Tr>
  auto
  SListHandler<T, Tr>::vector_to_slist (const VectorType& vector) ->
      typename SListHandler<T, Tr>::GSListKeeperType
  {
    return GSListKeeperType (
        Glib::Container_Helpers::create_gslist<Tr> (vector.begin (),
                                                    vector.end ()),
        Glib::OWNERSHIP_SHALLOW);
  }

#endif

} // namespace Glib

#endif
