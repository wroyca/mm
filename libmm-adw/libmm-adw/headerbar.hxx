// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_HEADERBAR_H
#define _LIBADWAITAMM_HEADERBAR_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class HeaderBar_Class;
}
#endif

namespace Adw
{

  enum class CenteringPolicy
  {
    LOOSE,
    STRICT
  };

} // namespace Adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class Value<Adw::CenteringPolicy>
    : public Glib::Value_Enum<Adw::CenteringPolicy>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

  class HeaderBar : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef HeaderBar CppObjectType;
    typedef HeaderBar_Class CppClassType;
    typedef AdwHeaderBar BaseObjectType;
    typedef AdwHeaderBarClass BaseClassType;
#endif

    HeaderBar (HeaderBar&& src) noexcept;
    auto
    operator= (HeaderBar&& src) noexcept -> HeaderBar&;

    HeaderBar (const HeaderBar&) = delete;
    auto
    operator= (const HeaderBar&) -> HeaderBar& = delete;

    ~HeaderBar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class HeaderBar_Class;
    static CppClassType headerbar_class_;

  protected:
    explicit HeaderBar (const Glib::ConstructParams& construct_params);
    explicit HeaderBar (AdwHeaderBar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwHeaderBar*
    {
      return reinterpret_cast<AdwHeaderBar*> (gobject_);
    }

    auto
    gobj () const -> const AdwHeaderBar*
    {
      return reinterpret_cast<AdwHeaderBar*> (gobject_);
    }

  private:
  public:
    HeaderBar ();

    auto
    get_centering_policy () const -> CenteringPolicy;

    auto
    get_decoration_layout () const -> Glib::ustring;

    auto
    get_show_end_title_buttons () const -> bool;

    auto
    get_show_start_title_buttons () const -> bool;

    auto
    get_title_widget () const -> Gtk::Widget*;

    auto
    pack_end (Gtk::Widget* child) -> void;

    auto
    pack_start (Gtk::Widget* child) -> void;

    auto
    remove (Gtk::Widget* child) -> void;

    auto
    set_centering_policy (CenteringPolicy centering_policy) -> void;

    auto
    set_decoration_layout (const Glib::ustring& layout) -> void;

    auto
    set_show_end_title_buttons (bool setting) -> void;

    auto
    set_show_start_title_buttons (bool setting) -> void;

    auto
    set_title_widget (Gtk::Widget* title_widget) -> void;

    auto
    property_centering_policy () -> Glib::PropertyProxy<CenteringPolicy>;

    auto
    property_centering_policy () const
        -> Glib::PropertyProxy_ReadOnly<CenteringPolicy>;

    auto
    property_decoration_layout () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_decoration_layout () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_show_end_title_buttons () -> Glib::PropertyProxy<bool>;

    auto
    property_show_end_title_buttons () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_start_title_buttons () -> Glib::PropertyProxy<bool>;

    auto
    property_show_start_title_buttons () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_title_widget () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_title_widget () const
        -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwHeaderBar* object, bool take_copy = false) -> Adw::HeaderBar*;
}

#endif
