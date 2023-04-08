// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_AVATAR_H
#define _LIBADWAITAMM_AVATAR_H

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
  class LIBMM_ADW_SYMEXPORT avatar_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT avatar : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = avatar;
    using CppClassType = avatar_class;
    using BaseObjectType = AdwAvatar;
    using BaseClassType = AdwAvatarClass;
#endif

    avatar (avatar&& src) noexcept;
    auto
    operator= (avatar&& src) noexcept -> avatar&;

    avatar (const avatar&) = delete;
    auto
    operator= (const avatar&) -> avatar& = delete;

    ~avatar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class avatar_class;
    static CppClassType avatar_class_;

  protected:
    explicit avatar (const glib::ConstructParams& construct_params);
    explicit avatar (AdwAvatar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwAvatar*
    {
      return reinterpret_cast<AdwAvatar*> (gobject_);
    }

    auto
    gobj () const -> const AdwAvatar*
    {
      return reinterpret_cast<AdwAvatar*> (gobject_);
    }

  private:
  public:
    avatar ();
    explicit avatar (int size, const glib::ustring& text, bool show_initials);

    auto
    draw_to_texture (int scale_factor) -> glib::RefPtr<gdk::Texture>;

    auto
    get_custom_image () const -> glib::RefPtr<gdk::Paintable>;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    get_show_initials () const -> bool;

    auto
    get_size () const -> int;

    auto
    get_text () const -> glib::ustring;

    auto
    set_custom_image (const glib::RefPtr<gdk::Paintable>& custom_image) -> void;

    auto
    set_icon_name (const glib::ustring& icon_name) -> void;

    auto
    set_show_initials (bool show_initials) -> void;

    auto
    set_size (int size) -> void;

    auto
    set_text (const glib::ustring& text) -> void;

    auto
    property_size () -> glib::PropertyProxy<int>;

    auto
    property_size () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_custom_image ()
        -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>;

    auto
    property_custom_image () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>;

    auto
    property_show_initials () -> glib::PropertyProxy<bool>;

    auto
    property_show_initials () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwAvatar* object, bool take_copy = false) -> adw::avatar*;
}

#endif
