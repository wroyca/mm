// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CLAMP_H
#define _LIBADWAITAMM_CLAMP_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT Clamp_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT Clamp : public gtk::Widget,
                public gtk::Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Clamp CppObjectType;
    typedef Clamp_Class CppClassType;
    typedef AdwClamp BaseObjectType;
    typedef AdwClampClass BaseClassType;
#endif

    Clamp (Clamp&& src) noexcept;
    auto
    operator= (Clamp&& src) noexcept -> Clamp&;

    Clamp (const Clamp&) = delete;
    auto
    operator= (const Clamp&) -> Clamp& = delete;

    ~Clamp () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class Clamp_Class;
    static CppClassType clamp_class_;

  protected:
    explicit Clamp (const glib::ConstructParams& construct_params);
    explicit Clamp (AdwClamp* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwClamp*
    {
      return reinterpret_cast<AdwClamp*> (gobject_);
    }

    auto
    gobj () const -> const AdwClamp*
    {
      return reinterpret_cast<AdwClamp*> (gobject_);
    }

  private:
  public:
    Clamp ();

    auto
    get_child () const -> gtk::Widget*;

    auto
    get_maximum_size () const -> int;

    auto
    get_tightening_threshold () const -> int;

    auto
    set_child (gtk::Widget* child) -> void;

    auto
    get_maximum_size (int maximum_size) -> void;

    auto
    get_tightening_threshold (int tightening_threshold) -> void;

    auto
    property_child () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_maximum_size () -> glib::PropertyProxy<int>;

    auto
    property_maximum_size () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_tightening_threshold () -> glib::PropertyProxy<int>;

    auto
    property_tightening_threshold () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwClamp* object, bool take_copy = false) -> adw::Clamp*;
}

#endif
