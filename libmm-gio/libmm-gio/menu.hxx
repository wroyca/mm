
#ifndef _GIOMM_MENU_H
#define _GIOMM_MENU_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/menuitem.hxx>
#include <libmm-gio/menumodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMenu = struct _GMenu;
using GMenuClass = struct _GMenuClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API Menu_Class;
}
#endif

namespace Gio
{

  class GIOMM_API Menu : public Gio::MenuModel
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
    explicit Menu (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<Menu>;

    void
    freeze ();

    void
    insert_item (int position, const Glib::RefPtr<const MenuItem>& item);

    void
    prepend_item (const Glib::RefPtr<const MenuItem>& item);

    void
    append_item (const Glib::RefPtr<const MenuItem>& item);

    void
    remove (int position);

    void
    remove_all ();

    void
    insert (int position,
            const Glib::ustring& label,
            const Glib::ustring& detailed_action);

    void
    insert (int position, const Glib::ustring& label);

    void
    prepend (const Glib::ustring& label, const Glib::ustring& detailed_action);

    void
    prepend (const Glib::ustring& label);

    void
    append (const Glib::ustring& label, const Glib::ustring& detailed_action);

    void
    append (const Glib::ustring& label);

    void
    insert_section (int position,
                    const Glib::ustring& label,
                    const Glib::RefPtr<MenuModel>& section);

    void
    insert_section (int position, const Glib::RefPtr<MenuModel>& section);

    void
    prepend_section (const Glib::ustring& label,
                     const Glib::RefPtr<MenuModel>& section);

    void
    prepend_section (const Glib::RefPtr<MenuModel>& section);

    void
    append_section (const Glib::ustring& label,
                    const Glib::RefPtr<MenuModel>& section);

    void
    append_section (const Glib::RefPtr<MenuModel>& section);

    void
    insert_submenu (int position,
                    const Glib::ustring& label,
                    const Glib::RefPtr<MenuModel>& submenu);

    void
    prepend_submenu (const Glib::ustring& label,
                     const Glib::RefPtr<MenuModel>& submenu);

    void
    append_submenu (const Glib::ustring& label,
                    const Glib::RefPtr<MenuModel>& submenu);

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GMenu* object, bool take_copy = false) -> Glib::RefPtr<Gio::Menu>;
} // namespace Glib

#endif
