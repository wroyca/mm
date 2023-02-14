
#ifndef _GTKMM_SHORTCUTMANAGER_H
#define _GTKMM_SHORTCUTMANAGER_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkShortcutManagerInterface GtkShortcutManagerInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutManager = struct _GtkShortcutManager;
using GtkShortcutManagerClass = struct _GtkShortcutManagerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ShortcutManager_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API ShortcutController;

  class GTKMM_API ShortcutManager : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ShortcutManager;
    using CppClassType = ShortcutManager_Class;
    using BaseObjectType = GtkShortcutManager;
    using BaseClassType = GtkShortcutManagerInterface;

    ShortcutManager (const ShortcutManager&) = delete;
    auto
    operator= (const ShortcutManager&) -> ShortcutManager& = delete;

  private:
    friend class ShortcutManager_Class;
    static CppClassType shortcutmanager_class_;

#endif
  protected:
    ShortcutManager ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit ShortcutManager (const Glib::Interface_Class& interface_class);

  public:
    explicit ShortcutManager (GtkShortcutManager* castitem);

  protected:
#endif

  public:
    ShortcutManager (ShortcutManager&& src) noexcept;
    auto
    operator= (ShortcutManager&& src) noexcept -> ShortcutManager&;

    ~ShortcutManager () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkShortcutManager*
    {
      return reinterpret_cast<GtkShortcutManager*> (gobject_);
    }

    auto
    gobj () const -> const GtkShortcutManager*
    {
      return reinterpret_cast<GtkShortcutManager*> (gobject_);
    }

  private:
  public:
  protected:
    virtual void
    add_controller_vfunc (const Glib::RefPtr<ShortcutController>& controller);

    virtual void
    remove_controller_vfunc (
        const Glib::RefPtr<ShortcutController>& controller);

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkShortcutManager* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ShortcutManager>;

} // namespace Glib

#endif
