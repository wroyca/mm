
#ifndef _GTKMM_TREEEXPANDER_H
#define _GTKMM_TREEEXPANDER_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/treelistrow.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API TreeExpander_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API TreeExpander : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef TreeExpander CppObjectType;
    typedef TreeExpander_Class CppClassType;
    typedef GtkTreeExpander BaseObjectType;
    typedef GtkTreeExpanderClass BaseClassType;
#endif

    TreeExpander (TreeExpander&& src) noexcept;
    auto
    operator= (TreeExpander&& src) noexcept -> TreeExpander&;

    TreeExpander (const TreeExpander&) = delete;
    auto
    operator= (const TreeExpander&) -> TreeExpander& = delete;

    ~TreeExpander () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class TreeExpander_Class;
    static CppClassType treeexpander_class_;

  protected:
    explicit TreeExpander (const Glib::ConstructParams& construct_params);
    explicit TreeExpander (GtkTreeExpander* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTreeExpander*
    {
      return reinterpret_cast<GtkTreeExpander*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeExpander*
    {
      return reinterpret_cast<GtkTreeExpander*> (gobject_);
    }

  private:
  public:
    TreeExpander ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    void
    set_child (Widget& widget);

    void
    unset_child ();

    auto
    get_item () -> Glib::RefPtr<Glib::ObjectBase>;

    auto
    get_item () const -> Glib::RefPtr<const Glib::ObjectBase>;

    auto
    get_list_row () -> Glib::RefPtr<TreeListRow>;

    auto
    get_list_row () const -> Glib::RefPtr<const TreeListRow>;

    void
    set_list_row (const Glib::RefPtr<TreeListRow>& list_row);

    void
    unset_list_row ();

    auto
    get_indent_for_icon () const -> bool;

    void
    set_indent_for_icon (bool indent_for_icon = true);

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_item () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>>;

    auto
    property_list_row () -> Glib::PropertyProxy<Glib::RefPtr<TreeListRow>>;

    auto
    property_list_row () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeListRow>>;

    auto
    property_indent_for_icon () -> Glib::PropertyProxy<bool>;

    auto
    property_indent_for_icon () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkTreeExpander* object, bool take_copy = false) -> Gtk::TreeExpander*;
} // namespace Glib

#endif
