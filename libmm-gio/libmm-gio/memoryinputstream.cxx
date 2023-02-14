

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/memoryinputstream.hxx>
#include <libmm-gio/memoryinputstream_p.hxx>

#include <gio/gio.h>

namespace
{

  class SlotWithData
  {
  public:
    SlotWithData (const Gio::MemoryInputStream::SlotDestroyData& slot,
                  void* data)
      : m_slot (new Gio::MemoryInputStream::SlotDestroyData (slot)),
        m_data (data)
    {
    }

    SlotWithData (const SlotWithData& src) = delete;
    auto
    operator= (const SlotWithData& src) -> SlotWithData& = delete;

    ~SlotWithData ()
    {
      delete m_slot;
    }

    auto
    operator() () -> void
    {
      (*m_slot) (m_data);
    }

  private:
    Gio::MemoryInputStream::SlotDestroyData* m_slot;
    void* m_data;
  };

  auto
  destroy_data_callback (void* user_data) -> void
  {
    const auto slot_with_data = static_cast<SlotWithData*> (user_data);
    g_return_if_fail (slot_with_data != nullptr);

    try
    {
      (*slot_with_data) ();
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }

    delete slot_with_data;
  }

} // namespace

namespace Gio
{

  auto
  MemoryInputStream::add_data (const void* data,
                               const gssize len,
                               const SlotDestroyData& destroy_slot) -> void
  {
    const auto slot_with_data = new SlotWithData (destroy_slot,
                                                  const_cast<void*> (data));
    const auto bytes = g_bytes_new_with_free_func (data,
                                                   len,
                                                   &destroy_data_callback,
                                                   slot_with_data);
    g_memory_input_stream_add_bytes (gobj (), bytes);
    g_bytes_unref (bytes);
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GMemoryInputStream* object, const bool take_copy) -> RefPtr<Gio::MemoryInputStream>
  {
    return Glib::make_refptr_for_instance<Gio::MemoryInputStream> (
        dynamic_cast<Gio::MemoryInputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  MemoryInputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MemoryInputStream_Class::class_init_function;

      register_derived_type (g_memory_input_stream_get_type ());

      Seekable::add_interface (get_type ());
      PollableInputStream::add_interface (get_type ());
    }

    return *this;
  }

  auto
  MemoryInputStream_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MemoryInputStream_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MemoryInputStream ((GMemoryInputStream*) object);
  }

  auto
  MemoryInputStream::gobj_copy () -> GMemoryInputStream*
  {
    reference ();
    return gobj ();
  }

  MemoryInputStream::MemoryInputStream (
      const Glib::ConstructParams& construct_params)
    : InputStream (construct_params)
  {
  }

  MemoryInputStream::MemoryInputStream (GMemoryInputStream* castitem)
    : InputStream ((GInputStream*) castitem)
  {
  }

  MemoryInputStream::MemoryInputStream (MemoryInputStream&& src) noexcept
    : InputStream (std::move (src)),
      Seekable (std::move (src)),
      PollableInputStream (std::move (src))
  {
  }

  auto
  MemoryInputStream::operator= (MemoryInputStream&& src) noexcept -> MemoryInputStream&
  {
    InputStream::operator= (std::move (src));
    Seekable::operator= (std::move (src));
    PollableInputStream::operator= (std::move (src));
    return *this;
  }

  MemoryInputStream::~MemoryInputStream () noexcept = default;

  MemoryInputStream::CppClassType MemoryInputStream::memoryinputstream_class_;

  auto
  MemoryInputStream::get_type () -> GType
  {
    return memoryinputstream_class_.init ().get_type ();
  }

  auto
  MemoryInputStream::get_base_type () -> GType
  {
    return g_memory_input_stream_get_type ();
  }

  MemoryInputStream::MemoryInputStream ()
    : ObjectBase (nullptr),
      InputStream (Glib::ConstructParams (memoryinputstream_class_.init ()))
  {
  }

  auto
  MemoryInputStream::create () -> Glib::RefPtr<MemoryInputStream>
  {
    return Glib::make_refptr_for_instance<MemoryInputStream> (
        new MemoryInputStream ());
  }

  auto
  MemoryInputStream::add_data (const void* data,
                               const gssize len,
                               const GDestroyNotify destroy) -> void
  {
    g_memory_input_stream_add_data (gobj (), data, len, destroy);
  }

  auto
  MemoryInputStream::add_bytes (const Glib::RefPtr<const Glib::Bytes>& bytes) -> void
  {
    g_memory_input_stream_add_bytes (
        gobj (),
        const_cast<GBytes*> (Glib::unwrap<Glib::Bytes> (bytes)));
  }

} // namespace Gio
