// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/filenamecompleter.hxx>
#include <libmm/gio/filenamecompleter_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/file.hxx>
#include <libmm/glib/exceptionhandler.hxx>

namespace gio
{

}

namespace
{

  const glib::SignalProxyInfo
      FilenameCompleter_signal_got_completion_data_info = {
          "got_completion_data",
          (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
          (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GFilenameCompleter* object, const bool take_copy) -> RefPtr<gio::FilenameCompleter>
  {
    return glib::make_refptr_for_instance<gio::FilenameCompleter> (
        dynamic_cast<gio::FilenameCompleter*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  FilenameCompleter_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FilenameCompleter_Class::class_init_function;

      register_derived_type (g_filename_completer_get_type ());
    }

    return *this;
  }

  auto
  FilenameCompleter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->got_completion_data = &got_completion_data_callback;
  }

  auto
  FilenameCompleter_Class::got_completion_data_callback (
      GFilenameCompleter* self) -> void
  {
    const auto obj_base =
        glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_got_completion_data ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->got_completion_data)
      (*base->got_completion_data) (self);
  }

  auto
  FilenameCompleter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FilenameCompleter ((GFilenameCompleter*) object);
  }

  auto
  FilenameCompleter::gobj_copy () -> GFilenameCompleter*
  {
    reference ();
    return gobj ();
  }

  FilenameCompleter::FilenameCompleter (
      const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  FilenameCompleter::FilenameCompleter (GFilenameCompleter* castitem)
    : Object ((GObject*) castitem)
  {
  }

  FilenameCompleter::FilenameCompleter (FilenameCompleter&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  FilenameCompleter::operator= (FilenameCompleter&& src) noexcept -> FilenameCompleter&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  FilenameCompleter::~FilenameCompleter () noexcept = default;

  FilenameCompleter::CppClassType FilenameCompleter::filenamecompleter_class_;

  auto
  FilenameCompleter::get_type () -> GType
  {
    return filenamecompleter_class_.init ().get_type ();
  }

  auto
  FilenameCompleter::get_base_type () -> GType
  {
    return g_filename_completer_get_type ();
  }

  FilenameCompleter::FilenameCompleter ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (filenamecompleter_class_.init ()))
  {
  }

  auto
  FilenameCompleter::create () -> glib::RefPtr<FilenameCompleter>
  {
    return glib::make_refptr_for_instance<FilenameCompleter> (
        new FilenameCompleter ());
  }

  auto
  FilenameCompleter::get_completion_suffix (
      const std::string& initial_text) const -> std::string
  {
    return glib::convert_return_gchar_ptr_to_stdstring (
        g_filename_completer_get_completion_suffix (
            const_cast<GFilenameCompleter*> (gobj ()),
            initial_text.c_str ()));
  }

  auto
  FilenameCompleter::get_completions (const std::string& initial_text) const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        g_filename_completer_get_completions (
            const_cast<GFilenameCompleter*> (gobj ()),
            initial_text.c_str ()),
        glib::OWNERSHIP_DEEP);
  }

  auto
  FilenameCompleter::set_dirs_only (const bool dirs_only) -> void
  {
    g_filename_completer_set_dirs_only (gobj (), dirs_only);
  }

  auto
  FilenameCompleter::signal_got_completion_data () -> glib::SignalProxy<void ()>
  {
    return {this, &FilenameCompleter_signal_got_completion_data_info};
  }

  auto
  FilenameCompleter::on_got_completion_data () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->got_completion_data)
      (*base->got_completion_data) (gobj ());
  }

} // namespace gio
