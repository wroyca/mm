

#ifndef _GTKMM_OBJECT_H
#define _GTKMM_OBJECT_H

#include <libmm-glib/object.hxx>
#include <libmm-gtk/mm-gtkconfig.hxx>

#include <utility>

namespace Gtk
{

  class GTKMM_API Object;

  template <class T>
  auto
  manage (T* obj) -> T*
  {
    obj->set_manage ();
    return obj;
  }

  template <class T, class... T_Args>
  auto
  make_managed (T_Args&&... args)
  {
    return manage (new T (std::forward<T_Args> (args)...));
  }

  class GTKMM_API Object : public Glib::Object
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Object CppObjectType;
    typedef Glib::Object_Class CppClassType;
    typedef GObject BaseObjectType;
    typedef GObjectClass BaseClassType;
#endif

    Object (Object&& src) noexcept;
    auto
    operator= (Object&& src) noexcept -> Object&;

    ~Object () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class Object_Class;
    static CppClassType object_class_;

    Object (const Object&);
    auto
    operator= (const Object&) -> Object&;

  protected:
    explicit Object (const Glib::ConstructParams& construct_params);
    explicit Object (GObject* castitem);

#endif

  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_type () -> GType G_GNUC_CONST;
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    void
    set_manage () override;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    auto
    is_managed_ () const -> bool;
#endif

  protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    void
    destroy_ ();
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    void
    _init_unmanage ();
    void
    destroy_notify_ () override;
    void
    disconnect_cpp_wrapper (bool prevent_creation_of_another_wrapper = true);
    void
    _release_c_instance ();

    bool referenced_;
#endif
  };

} // namespace Gtk

#endif
