// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_BUTTONCONTENT_H
#define _LIBADWAITAMM_BUTTONCONTENT_H

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
  class LIBMM_ADW_SYMEXPORT button_content_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT button_content : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = button_content;
    using CppClassType = button_content_class;
    using BaseObjectType = AdwButtonContent;
    using BaseClassType = AdwButtonContentClass;
#endif

    button_content (button_content&& src) noexcept;
    auto
    operator= (button_content&& src) noexcept -> button_content&;

    button_content (const button_content&) = delete;
    auto
    operator= (const button_content&) -> button_content& = delete;

    ~button_content () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class button_content_class;
    static CppClassType buttoncontent_class_;

  protected:
    explicit button_content (const glib::ConstructParams& construct_params);
    explicit button_content (AdwButtonContent* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwButtonContent*
    {
      return reinterpret_cast<AdwButtonContent*> (gobject_);
    }

    auto
    gobj () const -> const AdwButtonContent*
    {
      return reinterpret_cast<AdwButtonContent*> (gobject_);
    }

  private:
  public:
    button_content ();

    auto
    get_icon_name () const -> glib::ustring;

    auto
    get_label () const -> glib::ustring;

    auto
    get_use_underline () const -> bool;

    auto
    set_icon_name (const glib::ustring& icon_name) -> void;

    auto
    set_label (const glib::ustring& label) -> void;

    auto
    set_use_underline (bool use_underline) -> void;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_use_underline () -> glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwButtonContent* object, bool take_copy = false) -> adw::button_content*;
}

#endif
