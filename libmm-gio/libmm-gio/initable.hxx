// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_INITABLE_H
#define _GIOMM_INITABLE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/cancellable.hxx>
#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GInitableIface GInitableIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GInitable = struct _GInitable;
using GInitableClass = struct _GInitableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API Initable_Class;
}
#endif

namespace Gio
{

  class GIOMM_API Initable : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Initable;
    using CppClassType = Initable_Class;
    using BaseObjectType = GInitable;
    using BaseClassType = GInitableIface;

    Initable (const Initable&) = delete;
    auto
    operator= (const Initable&) -> Initable& = delete;

  private:
    friend class Initable_Class;
    static CppClassType initable_class_;

#endif
  protected:
    Initable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Initable (const Glib::Interface_Class& interface_class);

  public:
    explicit Initable (GInitable* castitem);

  protected:
#endif

  public:
    Initable (Initable&& src) noexcept;
    auto
    operator= (Initable&& src) noexcept -> Initable&;

    ~Initable () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GInitable*
    {
      return reinterpret_cast<GInitable*> (gobject_);
    }

    auto
    gobj () const -> const GInitable*
    {
      return reinterpret_cast<GInitable*> (gobject_);
    }

  private:
  protected:
    auto
    init (const Glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    init () -> void;

  protected:
    virtual auto
    init_vfunc (const Glib::RefPtr<Cancellable>& cancellable, GError** error)
        -> bool;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GInitable* object, bool take_copy = false) -> Glib::RefPtr<Gio::Initable>;

} // namespace Glib

#endif
