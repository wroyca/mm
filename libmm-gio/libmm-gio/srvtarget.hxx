// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SRVTARGET_H
#define _GIOMM_SRVTARGET_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/value.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GSrvTarget GSrvTarget;
}
#endif

namespace Gio
{

  class GIOMM_API SrvTarget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = SrvTarget;
    using BaseObjectType = GSrvTarget;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    SrvTarget ();

    explicit SrvTarget (GSrvTarget* gobject, bool make_a_copy = true);

    SrvTarget (const SrvTarget& other);
    auto
    operator= (const SrvTarget& other) -> SrvTarget&;

    SrvTarget (SrvTarget&& other) noexcept;
    auto
    operator= (SrvTarget&& other) noexcept -> SrvTarget&;

    ~SrvTarget () noexcept;

    auto
    swap (SrvTarget& other) noexcept -> void;

    auto
    gobj () -> GSrvTarget*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GSrvTarget*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GSrvTarget*;

  protected:
    GSrvTarget* gobject_;

  private:
  public:
    SrvTarget (const Glib::ustring& hostname,
               guint16 port,
               guint16 priority,
               guint16 weight);

    auto
    get_hostname () const -> Glib::ustring;

    auto
    get_port () const -> guint16;

    auto
    get_priority () const -> guint16;

    auto
    get_weight () const -> guint16;
  };

} // namespace Gio

namespace Gio
{

  inline auto
  swap (SrvTarget& lhs, SrvTarget& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GSrvTarget* object, bool take_copy = false) -> Gio::SrvTarget;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class GIOMM_API Value<Gio::SrvTarget>
    : public Glib::Value_Boxed<Gio::SrvTarget>
  {
  };
#endif

} // namespace Glib

#endif
