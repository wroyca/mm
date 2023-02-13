


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/fileicon.hpp>
#include <libmm-gio/fileicon_p.hpp>


/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GFileIcon* object, const bool take_copy) -> RefPtr<Gio::FileIcon>
{
  return Glib::make_refptr_for_instance<Gio::FileIcon>( dynamic_cast<Gio::FileIcon*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto FileIcon_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileIcon_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_file_icon_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Icon::add_interface(get_type());
  LoadableIcon::add_interface(get_type());

  }

  return *this;
}


auto FileIcon_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto FileIcon_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FileIcon((GFileIcon*)object);
}


/* The implementation: */

auto FileIcon::gobj_copy() -> GFileIcon*
{
  reference();
  return gobj();
}

FileIcon::FileIcon(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

FileIcon::FileIcon(GFileIcon* castitem)
: Object((GObject*)castitem)
{}


FileIcon::FileIcon(FileIcon&& src) noexcept
: Object(std::move(src))
  , Icon(std::move(src))
  , LoadableIcon(std::move(src))
{}

auto FileIcon::operator=(FileIcon&& src) noexcept -> FileIcon&
{
  Object::operator=(std::move(src));
  Icon::operator=(std::move(src));
  LoadableIcon::operator=(std::move(src));
  return *this;
}


FileIcon::~FileIcon() noexcept = default;

FileIcon::CppClassType FileIcon::fileicon_class_; // initialize static member

auto FileIcon::get_type() -> GType
{
  return fileicon_class_.init().get_type();
}


auto FileIcon::get_base_type() -> GType
{
  return g_file_icon_get_type();
}


FileIcon::FileIcon()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(fileicon_class_.init()))
{


}

auto FileIcon::create() -> Glib::RefPtr<FileIcon>
{
  return Glib::make_refptr_for_instance<FileIcon>( new FileIcon() );
}

auto FileIcon::get_file() -> Glib::RefPtr<File>
{
  auto retvalue = Glib::wrap(g_file_icon_get_file(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto FileIcon::get_file() const -> Glib::RefPtr<const File>
{
  return const_cast<FileIcon*>(this)->get_file();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<File>>::value,
  "Type Glib::RefPtr<File> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto FileIcon::property_file() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<File> >
{
  return {this, "file"};
}


} // namespace Gio


