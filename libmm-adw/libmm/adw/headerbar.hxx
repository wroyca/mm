// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_HEADERBAR_H
#define _LIBADWAITAMM_HEADERBAR_H

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
  class LIBMM_ADW_SYMEXPORT header_bar_class;
}
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT CenteringPolicy
  {
    LOOSE,
    STRICT
  };

} // namespace adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<adw::CenteringPolicy>
    : public glib::Value_Enum<adw::CenteringPolicy>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT header_bar : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = header_bar;
    using CppClassType = header_bar_class;
    using BaseObjectType = AdwHeaderBar;
    using BaseClassType = AdwHeaderBarClass;
#endif

    header_bar (header_bar&& src) noexcept;
    auto
    operator= (header_bar&& src) noexcept -> header_bar&;

    header_bar (const header_bar&) = delete;
    auto
    operator= (const header_bar&) -> header_bar& = delete;

    ~header_bar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class header_bar_class;
    static CppClassType headerbar_class_;

  protected:
    explicit header_bar (const glib::ConstructParams& construct_params);
    explicit header_bar (AdwHeaderBar* castitem);

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
    header_bar ();

    auto
    get_centering_policy () const -> CenteringPolicy;

    auto
    get_decoration_layout () const -> glib::ustring;

    auto
    get_show_end_title_buttons () const -> bool;

    auto
    get_show_start_title_buttons () const -> bool;

    auto
    get_title_widget () const -> gtk::Widget*;

    auto
    pack_end (gtk::Widget* child) -> void;

    auto
    pack_start (gtk::Widget* child) -> void;

    auto
    remove (gtk::Widget* child) -> void;

    auto
    set_centering_policy (CenteringPolicy centering_policy) -> void;

    auto
    set_decoration_layout (const glib::ustring& layout) -> void;

    auto
    set_show_end_title_buttons (bool setting) -> void;

    auto
    set_show_start_title_buttons (bool setting) -> void;

    auto
    set_title_widget (gtk::Widget* title_widget) -> void;

    auto
    property_centering_policy () -> glib::PropertyProxy<CenteringPolicy>;

    auto
    property_centering_policy () const
        -> glib::PropertyProxy_ReadOnly<CenteringPolicy>;

    auto
    property_decoration_layout () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_decoration_layout () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_show_end_title_buttons () -> glib::PropertyProxy<bool>;

    auto
    property_show_end_title_buttons () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_start_title_buttons () -> glib::PropertyProxy<bool>;

    auto
    property_show_start_title_buttons () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_title_widget () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_title_widget () const
        -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwHeaderBar* object, bool take_copy = false) -> adw::header_bar*;
}

#endif
