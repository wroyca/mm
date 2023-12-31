// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/unixfdlist.hxx>
#include <libmm/gio/unixfdlist_p.hxx>

#include <gio/gunixfdlist.h>
#include <libmm/glib/error.hxx>

namespace gio
{

  UnixFDList::UnixFDList (const std::vector<int>& fds)
    : ObjectBase (nullptr),

      Object ((GObject*) g_unix_fd_list_new_from_array (
          glib::ArrayHandler<int>::vector_to_array (fds).data (),
          fds.size ()))
  {
  }

  UnixFDList::UnixFDList (const std::vector<int>& fds, const int n_fds)
    : ObjectBase (nullptr),

      Object ((GObject*) g_unix_fd_list_new_from_array (
          glib::ArrayHandler<int>::vector_to_array (fds).data (),
          n_fds))
  {
  }

  auto
  UnixFDList::peek_fds () const -> const std::vector<int>
  {
    int length = 0;
    const auto fds =
        g_unix_fd_list_peek_fds (const_cast<GUnixFDList*> (gobj ()), &length);

    return glib::ArrayHandler<int>::array_to_vector (fds,
                                                     length,
                                                     glib::OWNERSHIP_NONE);
  }

  auto
  UnixFDList::steal_fds () -> std::vector<int>
  {
    int length = 0;
    const auto fds = g_unix_fd_list_steal_fds (gobj (), &length);

    return glib::ArrayHandler<int>::array_to_vector (fds,
                                                     length,
                                                     glib::OWNERSHIP_DEEP);
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GUnixFDList* object, const bool take_copy) -> RefPtr<gio::UnixFDList>
  {
    return glib::make_refptr_for_instance<gio::UnixFDList> (
        dynamic_cast<gio::UnixFDList*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  UnixFDList_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &UnixFDList_Class::class_init_function;

      register_derived_type (g_unix_fd_list_get_type ());
    }

    return *this;
  }

  auto
  UnixFDList_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  UnixFDList_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new UnixFDList ((GUnixFDList*) object);
  }

  auto
  UnixFDList::gobj_copy () -> GUnixFDList*
  {
    reference ();
    return gobj ();
  }

  UnixFDList::UnixFDList (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  UnixFDList::UnixFDList (GUnixFDList* castitem)
    : Object ((GObject*) castitem)
  {
  }

  UnixFDList::UnixFDList (UnixFDList&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  UnixFDList::operator= (UnixFDList&& src) noexcept -> UnixFDList&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  UnixFDList::~UnixFDList () noexcept = default;

  UnixFDList::CppClassType UnixFDList::unixfdlist_class_;

  auto
  UnixFDList::get_type () -> GType
  {
    return unixfdlist_class_.init ().get_type ();
  }

  auto
  UnixFDList::get_base_type () -> GType
  {
    return g_unix_fd_list_get_type ();
  }

  UnixFDList::UnixFDList ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (unixfdlist_class_.init ()))
  {
  }

  auto
  UnixFDList::create () -> glib::RefPtr<UnixFDList>
  {
    return glib::make_refptr_for_instance<UnixFDList> (new UnixFDList ());
  }

  auto
  UnixFDList::create (const std::vector<int>& fds) -> glib::RefPtr<UnixFDList>
  {
    return glib::make_refptr_for_instance<UnixFDList> (new UnixFDList (fds));
  }

  auto
  UnixFDList::create (const std::vector<int>& fds, const int n_fds) -> glib::RefPtr<UnixFDList>
  {
    return glib::make_refptr_for_instance<UnixFDList> (
        new UnixFDList (fds, n_fds));
  }

  auto
  UnixFDList::get_length () const -> int
  {
    return g_unix_fd_list_get_length (const_cast<GUnixFDList*> (gobj ()));
  }

  auto
  UnixFDList::get (const int index) const -> int
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_unix_fd_list_get (const_cast<GUnixFDList*> (gobj ()), index, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  UnixFDList::append (const int fd) -> int
  {
    GError* gerror = nullptr;
    const auto retvalue = g_unix_fd_list_append (gobj (), fd, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

} // namespace gio
