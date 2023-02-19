// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_AVATAR_H
#define _LIBADWAITAMM_AVATAR_H

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
  class LIBMM_ADW_SYMEXPORT Avatar_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT Avatar : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Avatar CppObjectType;
    typedef Avatar_Class CppClassType;
    typedef AdwAvatar BaseObjectType;
    typedef AdwAvatarClass BaseClassType;
#endif

    Avatar (Avatar&& src) noexcept;
    auto
    operator= (Avatar&& src) noexcept -> Avatar&;

    Avatar (const Avatar&) = delete;
    auto
    operator= (const Avatar&) -> Avatar& = delete;

    ~Avatar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class Avatar_Class;
    static CppClassType avatar_class_;

  protected:
    explicit Avatar (const Glib::ConstructParams& construct_params);
    explicit Avatar (AdwAvatar* castitem);

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
    Avatar ();
    explicit Avatar (int size, const Glib::ustring& text, bool show_initials);

    auto
    draw_to_texture (int scale_factor) -> Glib::RefPtr<Gdk::Texture>;

    auto
    get_custom_image () const -> Glib::RefPtr<Gdk::Paintable>;

    auto
    get_icon_name () const -> Glib::ustring;

    auto
    get_show_initials () const -> bool;

    auto
    get_size () const -> int;

    auto
    get_text () const -> Glib::ustring;

    auto
    set_custom_image (const Glib::RefPtr<Gdk::Paintable>& custom_image) -> void;

    auto
    set_icon_name (const Glib::ustring& icon_name) -> void;

    auto
    set_show_initials (bool show_initials) -> void;

    auto
    set_size (int size) -> void;

    auto
    set_text (const Glib::ustring& text) -> void;

    auto
    property_size () -> Glib::PropertyProxy<int>;

    auto
    property_size () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_custom_image ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_custom_image () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_show_initials () -> Glib::PropertyProxy<bool>;

    auto
    property_show_initials () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwAvatar* object, bool take_copy = false) -> Adw::Avatar*;
}

#endif
