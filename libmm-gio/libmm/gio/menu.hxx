// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MENU_H
#define _GIOMM_MENU_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/menuitem.hxx>
#include <libmm/gio/menumodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMenu = struct _GMenu;
using GMenuClass = struct _GMenuClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT Menu_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Menu : public gio::MenuModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Menu;
    using CppClassType = Menu_Class;
    using BaseObjectType = GMenu;
    using BaseClassType = GMenuClass;

    Menu (const Menu&) = delete;
    auto
    operator= (const Menu&) -> Menu& = delete;

  private:
    friend class Menu_Class;
    static CppClassType menu_class_;

  protected:
    explicit Menu (const glib::ConstructParams& construct_params);
    explicit Menu (GMenu* castitem);

#endif

  public:
    Menu (Menu&& src) noexcept;
    auto
    operator= (Menu&& src) noexcept -> Menu&;

    ~Menu () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GMenu*
    {
      return reinterpret_cast<GMenu*> (gobject_);
    }

    auto
    gobj () const -> const GMenu*
    {
      return reinterpret_cast<GMenu*> (gobject_);
    }

    auto
    gobj_copy () -> GMenu*;

  private:
  protected:
    Menu ();

  public:
    static auto
    create () -> glib::RefPtr<Menu>;

    auto
    freeze () -> void;

    auto
    insert_item (int position, const glib::RefPtr<const MenuItem>& item)
        -> void;

    auto
    prepend_item (const glib::RefPtr<const MenuItem>& item) -> void;

    auto
    append_item (const glib::RefPtr<const MenuItem>& item) -> void;

    auto
    remove (int position) -> void;

    auto
    remove_all () -> void;

    auto
    insert (int position,
            const glib::ustring& label,
            const glib::ustring& detailed_action) -> void;

    auto
    insert (int position, const glib::ustring& label) -> void;

    auto
    prepend (const glib::ustring& label, const glib::ustring& detailed_action)
        -> void;

    auto
    prepend (const glib::ustring& label) -> void;

    auto
    append (const glib::ustring& label, const glib::ustring& detailed_action)
        -> void;

    auto
    append (const glib::ustring& label) -> void;

    auto
    insert_section (int position,
                    const glib::ustring& label,
                    const glib::RefPtr<MenuModel>& section) -> void;

    auto
    insert_section (int position, const glib::RefPtr<MenuModel>& section)
        -> void;

    auto
    prepend_section (const glib::ustring& label,
                     const glib::RefPtr<MenuModel>& section) -> void;

    auto
    prepend_section (const glib::RefPtr<MenuModel>& section) -> void;

    auto
    append_section (const glib::ustring& label,
                    const glib::RefPtr<MenuModel>& section) -> void;

    auto
    append_section (const glib::RefPtr<MenuModel>& section) -> void;

    auto
    insert_submenu (int position,
                    const glib::ustring& label,
                    const glib::RefPtr<MenuModel>& submenu) -> void;

    auto
    prepend_submenu (const glib::ustring& label,
                     const glib::RefPtr<MenuModel>& submenu) -> void;

    auto
    append_submenu (const glib::ustring& label,
                    const glib::RefPtr<MenuModel>& submenu) -> void;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GMenu* object, bool take_copy = false) -> glib::RefPtr<gio::Menu>;
} // namespace glib

#endif
