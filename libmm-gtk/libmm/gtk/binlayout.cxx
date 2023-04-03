// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/binlayout.hxx>
#include <libmm/gtk/binlayout_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkBinLayout* object, bool take_copy) -> Glib::RefPtr<Gtk::BinLayout>
  {
    return Glib::make_refptr_for_instance<Gtk::BinLayout> (
        dynamic_cast<Gtk::BinLayout*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  BinLayout_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &BinLayout_Class::class_init_function;

      gtype_ = gtk_bin_layout_get_type ();
    }

    return *this;
  }

  auto
  BinLayout_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  BinLayout_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new BinLayout ((GtkBinLayout*) object);
  }

  auto
  BinLayout::gobj_copy () -> GtkBinLayout*
  {
    reference ();
    return gobj ();
  }

  BinLayout::BinLayout (const Glib::ConstructParams& construct_params)
    : LayoutManager (construct_params)
  {
  }

  BinLayout::BinLayout (GtkBinLayout* castitem)
    : LayoutManager ((GtkLayoutManager*) (castitem))
  {
  }

  BinLayout::BinLayout (BinLayout&& src) noexcept
    : LayoutManager (std::move (src))
  {
  }

  auto
  BinLayout::operator= (BinLayout&& src) noexcept -> BinLayout&
  {
    LayoutManager::operator= (std::move (src));
    return *this;
  }

  BinLayout::~BinLayout () noexcept {}

  BinLayout::CppClassType BinLayout::binlayout_class_;

  auto
  BinLayout::get_type () -> GType
  {
    return binlayout_class_.init ().get_type ();
  }

  auto
  BinLayout::get_base_type () -> GType
  {
    return gtk_bin_layout_get_type ();
  }

  BinLayout::BinLayout ()
    : Glib::ObjectBase (nullptr),
      LayoutManager (Glib::ConstructParams (binlayout_class_.init ()))
  {
  }

  auto
  BinLayout::create () -> Glib::RefPtr<BinLayout>
  {
    return Glib::make_refptr_for_instance<BinLayout> (new BinLayout ());
  }

} // namespace Gtk
