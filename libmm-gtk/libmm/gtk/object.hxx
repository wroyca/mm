// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_OBJECT_H
#define _GTKMM_OBJECT_H

#include <libmm/glib/object.hxx>
#include <libmm/gtk/mm-gtkconfig.hxx>

#include <utility>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Object;

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

  class LIBMM_GTK_SYMEXPORT Object : public glib::Object
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Object CppObjectType;
    typedef glib::Object_Class CppClassType;
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
    explicit Object (const glib::ConstructParams& construct_params);
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

    auto
    set_manage () -> void override;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    auto
    is_managed_ () const -> bool;
#endif

  protected:
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    auto
    destroy_ () -> void;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    auto
    _init_unmanage () -> void;
    auto
    destroy_notify_ () -> void override;
    auto
    disconnect_cpp_wrapper (bool prevent_creation_of_another_wrapper = true)
        -> void;
    auto
    _release_c_instance () -> void;

    bool referenced_;
#endif
  };

} // namespace gtk

#endif
