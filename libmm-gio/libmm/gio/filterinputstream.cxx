// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/filterinputstream.hxx>
#include <libmm/gio/filterinputstream_p.hxx>

#include <gio/gio.h>

namespace gio
{

  FilterInputStream::FilterInputStream (
      const glib::RefPtr<InputStream>& base_stream)
    : ObjectBase (nullptr),
      InputStream (glib::ConstructParams (filterinputstream_class_.init (),
                                          "base_stream",
                                          glib::unwrap (base_stream),
                                          nullptr))
  {
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GFilterInputStream* object, const bool take_copy) -> RefPtr<gio::FilterInputStream>
  {
    return glib::make_refptr_for_instance<gio::FilterInputStream> (
        dynamic_cast<gio::FilterInputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  FilterInputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FilterInputStream_Class::class_init_function;

      register_derived_type (g_filter_input_stream_get_type ());
    }

    return *this;
  }

  auto
  FilterInputStream_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FilterInputStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FilterInputStream ((GFilterInputStream*) object);
  }

  auto
  FilterInputStream::gobj_copy () -> GFilterInputStream*
  {
    reference ();
    return gobj ();
  }

  FilterInputStream::FilterInputStream (
      const glib::ConstructParams& construct_params)
    : InputStream (construct_params)
  {
  }

  FilterInputStream::FilterInputStream (GFilterInputStream* castitem)
    : InputStream ((GInputStream*) castitem)
  {
  }

  FilterInputStream::FilterInputStream (FilterInputStream&& src) noexcept
    : InputStream (std::move (src))
  {
  }

  auto
  FilterInputStream::operator= (FilterInputStream&& src) noexcept -> FilterInputStream&
  {
    InputStream::operator= (std::move (src));
    return *this;
  }

  FilterInputStream::~FilterInputStream () noexcept = default;

  FilterInputStream::CppClassType FilterInputStream::filterinputstream_class_;

  auto
  FilterInputStream::get_type () -> GType
  {
    return filterinputstream_class_.init ().get_type ();
  }

  auto
  FilterInputStream::get_base_type () -> GType
  {
    return g_filter_input_stream_get_type ();
  }

  auto
  FilterInputStream::get_base_stream () -> glib::RefPtr<InputStream>
  {
    auto retvalue =
        glib::wrap (g_filter_input_stream_get_base_stream (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FilterInputStream::get_base_stream () const -> glib::RefPtr<const InputStream>
  {
    return const_cast<FilterInputStream*> (this)->get_base_stream ();
  }

  auto
  FilterInputStream::get_close_base_stream () const -> bool
  {
    return g_filter_input_stream_get_close_base_stream (
        const_cast<GFilterInputStream*> (gobj ()));
  }

  auto
  FilterInputStream::set_close_base_stream (const bool close_base) -> void
  {
    g_filter_input_stream_set_close_base_stream (gobj (), close_base);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<InputStream>>::value,
      "Type glib::RefPtr<InputStream> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FilterInputStream::property_base_stream () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<InputStream>>
  {
    return {this, "base-stream"};
  }

  auto
  FilterInputStream::property_close_base_stream () -> glib::PropertyProxy<bool>
  {
    return {this, "close-base-stream"};
  }

  auto
  FilterInputStream::property_close_base_stream () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "close-base-stream"};
  }

} // namespace gio
