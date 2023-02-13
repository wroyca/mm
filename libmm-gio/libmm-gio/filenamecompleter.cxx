


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/filenamecompleter.hpp>
#include <libmm-gio/filenamecompleter_p.hpp>


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

#include <libmm-glib/exceptionhandler.hpp>
#include <libmm-gio/file.hpp>
#include <gio/gio.h>

namespace Gio
{

} // namespace Gio

namespace
{


const Glib::SignalProxyInfo FilenameCompleter_signal_got_completion_data_info =
{
  "got_completion_data",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GFilenameCompleter* object, const bool take_copy) -> RefPtr<Gio::FilenameCompleter>
{
  return Glib::make_refptr_for_instance<Gio::FilenameCompleter>( dynamic_cast<Gio::FilenameCompleter*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto FilenameCompleter_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FilenameCompleter_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_filename_completer_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto FilenameCompleter_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->got_completion_data = &got_completion_data_callback;
}


auto FilenameCompleter_Class::got_completion_data_callback (GFilenameCompleter *self) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->on_got_completion_data();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->got_completion_data)
    (*base->got_completion_data)(self);
}


auto FilenameCompleter_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new FilenameCompleter((GFilenameCompleter*)object);
}


/* The implementation: */

auto FilenameCompleter::gobj_copy() -> GFilenameCompleter*
{
  reference();
  return gobj();
}

FilenameCompleter::FilenameCompleter(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

FilenameCompleter::FilenameCompleter(GFilenameCompleter* castitem)
: Object((GObject*)castitem)
{}


FilenameCompleter::FilenameCompleter(FilenameCompleter&& src) noexcept
: Object(std::move(src))
{}

auto FilenameCompleter::operator=(FilenameCompleter&& src) noexcept -> FilenameCompleter&
{
  Object::operator=(std::move(src));
  return *this;
}


FilenameCompleter::~FilenameCompleter() noexcept = default;

FilenameCompleter::CppClassType FilenameCompleter::filenamecompleter_class_; // initialize static member

auto FilenameCompleter::get_type() -> GType
{
  return filenamecompleter_class_.init().get_type();
}


auto FilenameCompleter::get_base_type() -> GType
{
  return g_filename_completer_get_type();
}


FilenameCompleter::FilenameCompleter()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(filenamecompleter_class_.init()))
{


}

auto FilenameCompleter::create() -> Glib::RefPtr<FilenameCompleter>
{
  return Glib::make_refptr_for_instance<FilenameCompleter>( new FilenameCompleter() );
}

auto FilenameCompleter::get_completion_suffix(const std::string& initial_text) const -> std::string
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_filename_completer_get_completion_suffix(const_cast<GFilenameCompleter*>(gobj()), initial_text.c_str()));
}

auto FilenameCompleter::get_completions(const std::string& initial_text) const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_filename_completer_get_completions(const_cast<GFilenameCompleter*>(gobj()), initial_text.c_str()), Glib::OWNERSHIP_DEEP);
}

auto FilenameCompleter::set_dirs_only (
  const bool dirs_only) -> void
{
  g_filename_completer_set_dirs_only(gobj(), dirs_only);
}


auto FilenameCompleter::signal_got_completion_data() -> Glib::SignalProxy<void()>
{
  return {this, &FilenameCompleter_signal_got_completion_data_info};
}


auto FilenameCompleter::on_got_completion_data () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->got_completion_data)
    (*base->got_completion_data)(gobj());
}


} // namespace Gio


