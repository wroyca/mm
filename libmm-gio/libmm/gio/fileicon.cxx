// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/fileicon.hxx>
#include <libmm/gio/fileicon_p.hxx>

#include <gio/gio.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GFileIcon* object, const bool take_copy) -> RefPtr<gio::FileIcon>
  {
    return glib::make_refptr_for_instance<gio::FileIcon> (
        dynamic_cast<gio::FileIcon*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  FileIcon_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileIcon_Class::class_init_function;

      register_derived_type (g_file_icon_get_type ());

      Icon::add_interface (get_type ());
      LoadableIcon::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FileIcon_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FileIcon_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FileIcon ((GFileIcon*) object);
  }

  auto
  FileIcon::gobj_copy () -> GFileIcon*
  {
    reference ();
    return gobj ();
  }

  FileIcon::FileIcon (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  FileIcon::FileIcon (GFileIcon* castitem)
    : Object ((GObject*) castitem)
  {
  }

  FileIcon::FileIcon (FileIcon&& src) noexcept
    : Object (std::move (src)),
      Icon (std::move (src)),
      LoadableIcon (std::move (src))
  {
  }

  auto
  FileIcon::operator= (FileIcon&& src) noexcept -> FileIcon&
  {
    Object::operator= (std::move (src));
    Icon::operator= (std::move (src));
    LoadableIcon::operator= (std::move (src));
    return *this;
  }

  FileIcon::~FileIcon () noexcept = default;

  FileIcon::CppClassType FileIcon::fileicon_class_;

  auto
  FileIcon::get_type () -> GType
  {
    return fileicon_class_.init ().get_type ();
  }

  auto
  FileIcon::get_base_type () -> GType
  {
    return g_file_icon_get_type ();
  }

  FileIcon::FileIcon ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (fileicon_class_.init ()))
  {
  }

  auto
  FileIcon::create () -> glib::RefPtr<FileIcon>
  {
    return glib::make_refptr_for_instance<FileIcon> (new FileIcon ());
  }

  auto
  FileIcon::get_file () -> glib::RefPtr<File>
  {
    auto retvalue = glib::wrap (g_file_icon_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileIcon::get_file () const -> glib::RefPtr<const File>
  {
    return const_cast<FileIcon*> (this)->get_file ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<glib::RefPtr<File>>::value,
      "Type glib::RefPtr<File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FileIcon::property_file () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<File>>
  {
    return {this, "file"};
  }

} // namespace gio
