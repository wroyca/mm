

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/filemonitor.hxx>
#include <libmm-gio/filemonitor_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/file.hxx>
#include <libmm-glib/exceptionhandler.hxx>

using Event = Gio::FileMonitor::Event;

namespace Gio
{

}

namespace
{

  auto
  FileMonitor_signal_changed_callback (GFileMonitor* self,
                                       GFile* p0,
                                       GFile* p1,
                                       GFileMonitorEvent p2,
                                       void* data) -> void
  {
    using namespace Gio;
    using SlotType = sigc::slot<
        void (const Glib::RefPtr<File>&, const Glib::RefPtr<File>&, Event)>;

    const auto obj = dynamic_cast<FileMonitor*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true),
                                            Glib::wrap (p1, true),
                                            static_cast<Event> (p2));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo FileMonitor_signal_changed_info = {
      "changed",
      (GCallback) &FileMonitor_signal_changed_callback,
      (GCallback) &FileMonitor_signal_changed_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GFileMonitor* object, const bool take_copy) -> RefPtr<Gio::FileMonitor>
  {
    return Glib::make_refptr_for_instance<Gio::FileMonitor> (
        dynamic_cast<Gio::FileMonitor*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  FileMonitor_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileMonitor_Class::class_init_function;

      register_derived_type (g_file_monitor_get_type ());
    }

    return *this;
  }

  auto
  FileMonitor_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->changed = &changed_callback;
  }

  auto
  FileMonitor_Class::changed_callback (GFileMonitor* self,
                                       GFile* p0,
                                       GFile* p1,
                                       GFileMonitorEvent p2) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_changed (Glib::wrap (p0, true),
                           Glib::wrap (p1, true),
                           static_cast<Event> (p2));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->changed)
      (*base->changed) (self, p0, p1, p2);
  }

  auto
  FileMonitor_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FileMonitor ((GFileMonitor*) object);
  }

  auto
  FileMonitor::gobj_copy () -> GFileMonitor*
  {
    reference ();
    return gobj ();
  }

  FileMonitor::FileMonitor (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  FileMonitor::FileMonitor (GFileMonitor* castitem)
    : Object ((GObject*) castitem)
  {
  }

  FileMonitor::FileMonitor (FileMonitor&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  FileMonitor::operator= (FileMonitor&& src) noexcept -> FileMonitor&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  FileMonitor::~FileMonitor () noexcept = default;

  FileMonitor::CppClassType FileMonitor::filemonitor_class_;

  auto
  FileMonitor::get_type () -> GType
  {
    return filemonitor_class_.init ().get_type ();
  }

  auto
  FileMonitor::get_base_type () -> GType
  {
    return g_file_monitor_get_type ();
  }

  auto
  FileMonitor::cancel () -> bool
  {
    return g_file_monitor_cancel (gobj ());
  }

  auto
  FileMonitor::is_cancelled () const -> bool
  {
    return g_file_monitor_is_cancelled (const_cast<GFileMonitor*> (gobj ()));
  }

  auto
  FileMonitor::set_rate_limit (const int limit_msecs) -> void
  {
    g_file_monitor_set_rate_limit (gobj (), limit_msecs);
  }

  auto
  FileMonitor::signal_changed () -> Glib::SignalProxy<
      void (const Glib::RefPtr<File>&, const Glib::RefPtr<File>&, Event)>
  {
    return {this, &FileMonitor_signal_changed_info};
  }

  auto
  FileMonitor::property_rate_limit () -> Glib::PropertyProxy<int>
  {
    return {this, "rate-limit"};
  }

  auto
  FileMonitor::property_rate_limit () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "rate-limit"};
  }

  auto
  FileMonitor::property_cancelled () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "cancelled"};
  }

  auto
  FileMonitor::on_changed (const Glib::RefPtr<File>& file,
                           const Glib::RefPtr<File>& other_file,
                           Event event_type) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->changed)
      (*base->changed) (gobj (),
                        Glib::unwrap (file),
                        Glib::unwrap (other_file),
                        static_cast<GFileMonitorEvent> (event_type));
  }

} // namespace Gio
