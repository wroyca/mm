
#ifndef _GLIBMM_NODETREE_H
#define _GLIBMM_NODETREE_H

#include <deque>
#include <map>
#include <stack>

#include <glib.h>
#include <libmm-glib/error.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>
#include <sigc++/bind.h>
#include <sigc++/slot.h>

namespace Glib
{

  template <typename T>
  class NodeTree
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = NodeTree;
    using BaseObjectType = GNode;
#endif

  private:
  public:
    enum class TraverseType
    {
      IN_ORDER,
      PRE_ORDER,
      POST_ORDER,
      LEVEL_ORDER
    };

    using TraverseFunc = sigc::slot<bool (NodeTree<T>&)>;
    using ForeachFunc = sigc::slot<void (NodeTree<T>&)>;

  private:
    static auto
    wrap (GNode* node) -> NodeTree<T>*
    {
      if (!node)
        return nullptr;

      return reinterpret_cast<NodeTree<T>*> (node->data);
    }

  public:
    NodeTree ()
    {
      clone ();
    }

    explicit NodeTree (const T& the_data)
      : data_ (the_data)
    {
      clone ();
    }

    NodeTree (const NodeTree<T>& node)
      : data_ (node.data ())
    {
      clone (&node);
    }

    ~NodeTree ()
    {
      if (!is_root ())
        unlink ();

      clear ();
    }

    auto
    operator= (const NodeTree<T>& node) -> NodeTree<T>&
    {
      clear ();
      clone (&node);

      data_ = node.data ();

      return *this;
    }

    inline auto
    gobj () -> GNode*
    {
      return gobject_;
    }

    inline auto
    gobj () const -> const GNode*
    {
      return gobject_;
    }

    auto
    insert (int position, NodeTree<T>& node) -> NodeTree<T>&
    {
      g_node_insert (gobj (), position, node.gobj ());
      return node;
    }

    auto
    insert_before (NodeTree<T>& sibling, NodeTree<T>& node) -> NodeTree<T>&
    {
      g_node_insert_before (gobj (), sibling.gobj (), node.gobj ());
      return node;
    }

    auto
    insert_after (NodeTree<T>& sibling, NodeTree<T>& node) -> NodeTree<T>&
    {
      g_node_insert_after (gobj (), sibling.gobj (), node.gobj ());
      return node;
    }

    auto
    append (NodeTree<T>& node) -> NodeTree<T>&
    {
      g_node_append (gobj (), node.gobj ());
      return node;
    }

    auto
    prepend (NodeTree<T>& node) -> NodeTree<T>&
    {
      g_node_prepend (gobj (), node.gobj ());
      return node;
    }

    auto
    insert_data (int position, const T& the_data) -> NodeTree<T>*
    {
      NodeTree<T>* node = new NodeTree<T> (the_data);
      insert (position, *node);
      return node;
    }

    auto
    insert_data_before (NodeTree<T>& sibling, const T& the_data) -> NodeTree<T>*
    {
      NodeTree<T>* node = new NodeTree<T> (the_data);
      insert_before (sibling, *node);
      return node;
    }

    auto
    append_data (const T& the_data) -> NodeTree<T>*
    {
      NodeTree<T>* node = new NodeTree<T> (the_data);
      append (*node);
      return node;
    }

    auto
    prepend_data (const T& the_data) -> NodeTree<T>*
    {
      NodeTree<T>* node = new NodeTree<T> (the_data);
      prepend (*node);
      return node;
    }

    void
    reverse_children ()
    {
      g_node_reverse_children (gobj ());
    }

    auto
    get_root () -> NodeTree<T>*
    {
      return wrap (g_node_get_root (gobj ()));
    }

    auto
    get_root () const -> const NodeTree<T>*
    {
      return wrap (g_node_get_root (const_cast<GNode*> (gobj ())));
    }

    enum class TraverseFlags
    {
      LEAVES = G_TRAVERSE_LEAVES,
      NON_LEAVES = G_TRAVERSE_NON_LEAVES,
      ALL = G_TRAVERSE_ALL,
      MASK = G_TRAVERSE_MASK
    };

    void
    traverse (const TraverseFunc& func,
              TraverseType order = TraverseType::IN_ORDER,
              TraverseFlags flags = TraverseFlags::ALL,
              int max_depth = -1)
    {
      TraverseFunc func_copy = func;
      g_node_traverse (gobj (),
                       (GTraverseType) order,
                       (GTraverseFlags) flags,
                       max_depth,
                       c_callback_traverse,
                       reinterpret_cast<gpointer> (&func_copy));
    };

    void foreach (const ForeachFunc& func,
                  TraverseFlags flags = TraverseFlags::ALL)
    {
      ForeachFunc func_copy = func;
      g_node_children_foreach (gobj (),
                               (GTraverseFlags) flags,
                               c_callback_foreach,
                               reinterpret_cast<gpointer> (&func_copy));
    }

    auto
    find_child (const T& the_data, TraverseFlags flags = TraverseFlags::ALL)
        -> NodeTree<T>*
    {
      sigc::slot<void (GNode*, const T&, GNode**)> real_slot =
          sigc::ptr_fun (on_compare_child);

      GNode* child = nullptr;
      using type_foreach_gnode_slot = sigc::slot<void (GNode*)>;
      type_foreach_gnode_slot bound_slot =
          sigc::bind (real_slot, the_data, &child);

      g_node_children_foreach (gobj (),
                               (GTraverseFlags) flags,
                               c_callback_foreach_compare_child,
                               reinterpret_cast<gpointer> (&bound_slot));

      return wrap (child);
    }

    auto
    find_child (const T& the_data,
                TraverseFlags flags = TraverseFlags::ALL) const
        -> const NodeTree<T>*
    {
      return const_cast<NodeTree<T>*> (this)->find_child (flags, the_data);
    }

    auto
    find (const T& the_data,
          TraverseType order = TraverseType::IN_ORDER,
          TraverseFlags flags = TraverseFlags::ALL) -> NodeTree<T>*
    {
      sigc::slot<gboolean (GNode*, const T&, GNode**)> real_slot =
          sigc::ptr_fun (on_compare_node);
      GNode* child = nullptr;

      using type_traverse_gnode_slot = sigc::slot<gboolean (GNode*)>;
      type_traverse_gnode_slot bound_slot =
          sigc::bind (real_slot, the_data, &child);

      g_node_traverse (const_cast<GNode*> (gobj ()),
                       (GTraverseType) order,
                       (GTraverseFlags) flags,
                       -1,
                       c_callback_traverse_compare_node,
                       reinterpret_cast<gpointer> (&bound_slot));

      return wrap (child);
    }

    auto
    find (const T& the_data,
          TraverseType order = TraverseType::IN_ORDER,
          TraverseFlags flags = TraverseFlags::ALL) const -> const NodeTree<T>*
    {
      return const_cast<NodeTree<T>*> (this)->find (order, flags, the_data);
    }

    auto
    child_index (const T& the_data) const -> int
    {
      int n = 0;

      for (const NodeTree<T>* i = first_child (); i != nullptr;
           i = i->next_sibling ())
      {
        if ((i->data ()) == the_data)
          return n;

        n++;
      }

      return -1;
    }

    auto
    child_position (const NodeTree<T>& child) const -> int
    {
      return g_node_child_position (const_cast<GNode*> (gobj ()),
                                    const_cast<GNode*> (child.gobj ()));
    }

    auto
    first_child () -> NodeTree<T>*
    {
      return wrap (g_node_first_child (gobj ()));
    }

    auto
    first_child () const -> const NodeTree<T>*
    {
      return const_cast<NodeTree<T>*> (this)->first_child ();
    }

    auto
    last_child () -> NodeTree<T>*
    {
      return wrap (g_node_last_child (gobj ()));
    }

    auto
    last_child () const -> const NodeTree<T>*
    {
      return const_cast<NodeTree<T>*> (this)->last_child ();
    }

    auto
    nth_child (int n) -> NodeTree<T>*
    {
      return wrap (g_node_nth_child (gobj (), n));
    }

    auto
    nth_child (int n) const -> const NodeTree<T>*
    {
      return const_cast<NodeTree<T>*> (this)->nth_child (n);
    }

    auto
    first_sibling () -> NodeTree<T>*
    {
      return wrap (g_node_first_sibling (gobj ()));
    }

    auto
    first_sibling () const -> const NodeTree<T>*
    {
      return const_cast<NodeTree<T>*> (this)->first_sibling ();
    }

    auto
    prev_sibling () -> NodeTree<T>*
    {
      return wrap (g_node_prev_sibling (gobj ()));
    }

    auto
    prev_sibling () const -> const NodeTree<T>*
    {
      return const_cast<NodeTree<T>*> (this)->prev_sibling ();
    }

    auto
    next_sibling () -> NodeTree<T>*
    {
      return wrap (g_node_next_sibling (gobj ()));
    }

    auto
    next_sibling () const -> const NodeTree<T>*
    {
      return const_cast<NodeTree<T>*> (this)->next_sibling ();
    }

    auto
    last_sibling () -> NodeTree<T>*
    {
      return wrap (g_node_last_sibling (gobj ()));
    }

    auto
    last_sibling () const -> const NodeTree<T>*
    {
      return const_cast<NodeTree<T>*> (this)->last_sibling ();
    }

    auto
    is_leaf () const -> bool
    {
      return G_NODE_IS_LEAF (const_cast<GNode*> (gobj ()));
    }

    auto
    is_root () const -> bool
    {
      return G_NODE_IS_ROOT (const_cast<GNode*> (gobj ()));
    }

    auto
    depth () const -> guint
    {
      return g_node_depth (const_cast<GNode*> (gobj ()));
    }

    auto
    node_count (TraverseFlags flags = TraverseFlags::ALL) const -> guint
    {
      return g_node_n_nodes (const_cast<GNode*> (gobj ()),
                             (GTraverseFlags) flags);
    }

    auto
    child_count () const -> guint
    {
      return g_node_n_children (const_cast<GNode*> (gobj ()));
    }

    auto
    is_ancestor (const NodeTree<T>& descendant) const -> bool
    {
      return g_node_is_ancestor (const_cast<GNode*> (gobj ()),
                                 const_cast<GNode*> (descendant.gobj ()));
    }

    auto
    get_max_height () const -> guint
    {
      return g_node_max_height (const_cast<GNode*> (gobj ()));
    }

    void
    unlink ()
    {
      g_node_unlink (gobj ());
    }

#if 0 
  
  NodeTree<T>* copy_deep() const
  {
    
    return new NodeTree<T>(*this);
  }
#endif

    auto
    data () -> T&
    {
      return data_;
    }

    auto
    data () const -> const T&
    {
      return data_;
    }

    auto
    parent () const -> const NodeTree<T>*
    {
      return wrap (gobj ()->parent);
    }

  private:
    void
    clear ()
    {
      while (NodeTree<T>* i = first_child ())
        delete i;

      g_slice_free (GNode, gobject_);
      gobject_ = nullptr;
    }

    void
    clone (const NodeTree<T>* node = nullptr)
    {
      gobject_ = g_node_new (reinterpret_cast<gpointer> (this));

      if (node)
      {
        for (const NodeTree<T>* i = node->last_child (); i != nullptr;
             i = i->prev_sibling ())
          prepend (*(new NodeTree<T> (*i)));
      }
    }

    static auto
    c_callback_traverse (GNode* node, gpointer slot) -> gboolean
    {
      const TraverseFunc* tf = reinterpret_cast<const TraverseFunc*> (slot);
      return (*tf) (*wrap (node));
    }

    static void
    c_callback_foreach (GNode* node, gpointer slot)
    {
      const ForeachFunc* ff = reinterpret_cast<const ForeachFunc*> (slot);
      (*ff) (*wrap (node));
    }

    static void
    on_compare_child (GNode* node, const T& needle, GNode** result)
    {
      if ((nullptr != result) && (wrap (node)->data () == needle))
      {
        *result = node;
      }
    }

    static void
    c_callback_foreach_compare_child (GNode* node, gpointer data)
    {
      const ForeachFunc* slot = reinterpret_cast<const ForeachFunc*> (data);
      (*slot) (*wrap (node));
    }

    static auto
    on_compare_node (GNode* node, const T& needle, GNode** result) -> gboolean
    {
      if (wrap (node)->data () == needle)
      {
        *result = node;
        return TRUE;
      }
      return FALSE;
    }

    static auto
    c_callback_traverse_compare_node (GNode* node, gpointer data) -> gboolean
    {
      const TraverseFunc* slot = reinterpret_cast<const TraverseFunc*> (data);
      return (*slot) (*wrap (node));
    }

    GNode* gobject_;
    T data_;
  };

} // namespace Glib

#endif
