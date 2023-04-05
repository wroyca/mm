// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/notebookpage.hxx>
#include <libmm/gtk/notebookpage_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/widget.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkNotebookPage* object, bool take_copy) -> glib::RefPtr<gtk::NotebookPage>
  {
    return glib::make_refptr_for_instance<gtk::NotebookPage> (
        dynamic_cast<gtk::NotebookPage*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  NotebookPage_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &NotebookPage_Class::class_init_function;

      register_derived_type (gtk_notebook_page_get_type ());
    }

    return *this;
  }

  auto
  NotebookPage_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  NotebookPage_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new NotebookPage ((GtkNotebookPage*) object);
  }

  auto
  NotebookPage::gobj_copy () -> GtkNotebookPage*
  {
    reference ();
    return gobj ();
  }

  NotebookPage::NotebookPage (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  NotebookPage::NotebookPage (GtkNotebookPage* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  NotebookPage::NotebookPage (NotebookPage&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  NotebookPage::operator= (NotebookPage&& src) noexcept -> NotebookPage&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  NotebookPage::~NotebookPage () noexcept {}

  NotebookPage::CppClassType NotebookPage::notebookpage_class_;

  auto
  NotebookPage::get_type () -> GType
  {
    return notebookpage_class_.init ().get_type ();
  }

  auto
  NotebookPage::get_base_type () -> GType
  {
    return gtk_notebook_page_get_type ();
  }

  auto
  NotebookPage::get_child () -> Widget*
  {
    return glib::wrap (gtk_notebook_page_get_child (gobj ()));
  }

  auto
  NotebookPage::get_child () const -> const Widget*
  {
    return const_cast<NotebookPage*> (this)->get_child ();
  }

  auto
  NotebookPage::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

  auto
  NotebookPage::property_tab () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "tab");
  }

  auto
  NotebookPage::property_menu () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "menu");
  }

  auto
  NotebookPage::property_tab_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "tab-label");
  }

  auto
  NotebookPage::property_tab_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "tab-label");
  }

  auto
  NotebookPage::property_menu_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "menu-label");
  }

  auto
  NotebookPage::property_menu_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "menu-label");
  }

  auto
  NotebookPage::property_position () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "position");
  }

  auto
  NotebookPage::property_position () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "position");
  }

  auto
  NotebookPage::property_tab_expand () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "tab-expand");
  }

  auto
  NotebookPage::property_tab_expand () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "tab-expand");
  }

  auto
  NotebookPage::property_tab_fill () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "tab-fill");
  }

  auto
  NotebookPage::property_tab_fill () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "tab-fill");
  }

  auto
  NotebookPage::property_reorderable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "reorderable");
  }

  auto
  NotebookPage::property_reorderable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "reorderable");
  }

  auto
  NotebookPage::property_detachable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "detachable");
  }

  auto
  NotebookPage::property_detachable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "detachable");
  }

} // namespace gtk
