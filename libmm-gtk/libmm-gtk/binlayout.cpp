


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/binlayout.hpp>
#include <libmm-gtk/binlayout_p.hpp>


/* Copyright (C) 2019 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>


namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkBinLayout* object, const bool take_copy) -> RefPtr<Gtk::BinLayout>
{
  return Glib::make_refptr_for_instance<Gtk::BinLayout>( dynamic_cast<Gtk::BinLayout*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto BinLayout_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &BinLayout_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_bin_layout_get_type();

  }

  return *this;
}


auto BinLayout_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto BinLayout_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new BinLayout((GtkBinLayout*)object);
}


/* The implementation: */

auto BinLayout::gobj_copy() -> GtkBinLayout*
{
  reference();
  return gobj();
}

BinLayout::BinLayout(const Glib::ConstructParams& construct_params)
:
  LayoutManager(construct_params)
{

}

BinLayout::BinLayout(GtkBinLayout* castitem)
:
  LayoutManager((GtkLayoutManager*)castitem)
{}


BinLayout::BinLayout(BinLayout&& src) noexcept
: LayoutManager(std::move(src))
{}

auto BinLayout::operator=(BinLayout&& src) noexcept -> BinLayout&
{
  LayoutManager::operator=(std::move(src));
  return *this;
}


BinLayout::~BinLayout() noexcept = default;

BinLayout::CppClassType BinLayout::binlayout_class_; // initialize static member

auto BinLayout::get_type() -> GType
{
  return binlayout_class_.init().get_type();
}


auto BinLayout::get_base_type() -> GType
{
  return gtk_bin_layout_get_type();
}


BinLayout::BinLayout()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  LayoutManager(Glib::ConstructParams(binlayout_class_.init()))
{


}

auto BinLayout::create() -> Glib::RefPtr<BinLayout>
{
  return Glib::make_refptr_for_instance<BinLayout>( new BinLayout() );
}


} // namespace Gtk


