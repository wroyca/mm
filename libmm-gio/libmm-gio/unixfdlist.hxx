// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXFDLIST_H
#define _GIOMM_UNIXFDLIST_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixFDList = struct _GUnixFDList;
using GUnixFDListClass = struct _GUnixFDListClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API UnixFDList_Class;
}
#endif

namespace Gio
{

  class GIOMM_API UnixFDList : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = UnixFDList;
    using CppClassType = UnixFDList_Class;
    using BaseObjectType = GUnixFDList;
    using BaseClassType = GUnixFDListClass;

    UnixFDList (const UnixFDList&) = delete;
    auto
    operator= (const UnixFDList&) -> UnixFDList& = delete;

  private:
    friend class UnixFDList_Class;
    static CppClassType unixfdlist_class_;

  protected:
    explicit UnixFDList (const Glib::ConstructParams& construct_params);
    explicit UnixFDList (GUnixFDList* castitem);

#endif

  public:
    UnixFDList (UnixFDList&& src) noexcept;
    auto
    operator= (UnixFDList&& src) noexcept -> UnixFDList&;

    ~UnixFDList () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GUnixFDList*
    {
      return reinterpret_cast<GUnixFDList*> (gobject_);
    }

    auto
    gobj () const -> const GUnixFDList*
    {
      return reinterpret_cast<GUnixFDList*> (gobject_);
    }

    auto
    gobj_copy () -> GUnixFDList*;

  private:
  protected:
    UnixFDList ();

    explicit UnixFDList (const std::vector<int>& fds);

    explicit UnixFDList (const std::vector<int>& fds, int n_fds);

  public:
    static auto
    create () -> Glib::RefPtr<UnixFDList>;

    static auto
    create (const std::vector<int>& fds) -> Glib::RefPtr<UnixFDList>;

    static auto
    create (const std::vector<int>& fds, int n_fds) -> Glib::RefPtr<UnixFDList>;

    auto
    get_length () const -> int;

    auto
    get (int index) const -> int;

    auto
    peek_fds () const -> const std::vector<int>;

    auto
    steal_fds () -> std::vector<int>;

    auto
    append (int fd) -> int;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GUnixFDList* object, bool take_copy = false) -> Glib::RefPtr<Gio::UnixFDList>;
} // namespace Glib

#endif
