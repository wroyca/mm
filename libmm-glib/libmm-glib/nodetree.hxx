
#ifndef _GLIBMM_NODETREE_H
#define _GLIBMM_NODETREE_H


/* Copyright (C) 2007 glibmm development team
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


#include <map>
#include <stack>
#include <deque>

#include <sigc++/bind.h>
#include <sigc++/slot.h>
#include <libmm-glib/refptr.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/error.hxx>
#include <glib.h>

namespace Glib
{

/** N-ary Trees - trees of data with any number of branches
 * The NodeTree class and its associated functions provide an N-ary tree data structure, in which nodes in the tree can contain arbitrary data.
 *
 * To insert a node into a tree use insert(), insert_before(), append() or prepend().
 *
 * To create a new node and insert it into a tree use insert_data(), insert_data_before(), append_data() and prepend_data().
 *
 * To reverse the children of a node use reverse_children().
 *
 * To find a node use root(), find(), find_child(), index_of(), child_index(), first_child(), last_child(), nth_child(), first_sibling(), prev_sibling(), next_sibling() or last_sibling().
 *
 * To get information about a node or tree use is_leaf(), is_root(), depth(), node_count(), child_count(), is_ancestor() or max_height().
 *
 * To traverse a tree, calling a function for each node visited in the traversal, use traverse() or foreach().
 *
 * To remove a node or subtree from a tree use unlink().
 *
 * @newin{2,18}
 */
template <typename T>
class NodeTree
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = NodeTree;
  using BaseObjectType = GNode;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

public:
  /** @addtogroup glibmmEnums glibmm Enums and Flags */

  /**
   *  @var TraverseType IN_ORDER
   * Vists a node's left child first, then the node itself,
   * then its right child. This is the one to use if you
   * want the output sorted according to the compare
   * function.
   *
   *  @var TraverseType PRE_ORDER
   * Visits a node, then its children.
   *
   *  @var TraverseType POST_ORDER
   * Visits the node's children, then the node itself.
   *
   *  @var TraverseType LEVEL_ORDER
   * Is not implemented for
   * [balanced binary trees][glib-Balanced-Binary-Trees].
   * For [n-ary trees][glib-N-ary-Trees], it
   * vists the root node first, then its children, then
   * its grandchildren, and so on. Note that this is less
   * efficient than the other orders.
   *
   *  @enum TraverseType
   *
   * Specifies the type of traversal performed by g_tree_traverse(),
   * g_node_traverse() and g_node_find(). The different orders are
   * illustrated here:
   * - In order: A, B, C, D, E, F, G, H, I
   * ![](Sorted_binary_tree_inorder.svg)
   * - Pre order: F, B, A, D, C, E, G, I, H
   * ![](Sorted_binary_tree_preorder.svg)
   * - Post order: A, C, E, D, B, H, I, G, F
   * ![](Sorted_binary_tree_postorder.svg)
   * - Level order: F, B, G, A, D, I, C, E, H
   * ![](Sorted_binary_tree_breadth-first_traversal.svg)
   *
   * @ingroup glibmmEnums
   */
  enum class TraverseType
  {
    IN_ORDER,
    PRE_ORDER,
    POST_ORDER,
    LEVEL_ORDER
  };


  using TraverseFunc = sigc::slot<bool(NodeTree<T>&)>;
  using ForeachFunc = sigc::slot<void(NodeTree<T>&)>;

private:
  static auto wrap(GNode* node) -> NodeTree<T>*
  {
    if (!node)
      return nullptr;

    return reinterpret_cast<NodeTree<T>* >(node->data);
  }

public:
  NodeTree()
  {
    clone();
  }

  explicit NodeTree(const T& the_data) :
    data_(the_data)
  {
    clone();
  }


  NodeTree(const NodeTree<T>& node) :
    data_(node.data())
  {
    clone(&node);
  }

  //TODO: Add move operations, being careful of universal references and overload resolution.

  /** Removes the instance and its children from the tree,
   * freeing any memory allocated.
   */
  ~NodeTree()
  {
    if(!is_root())
      unlink();

    clear();
  }


  auto operator=(const NodeTree<T>& node) -> NodeTree<T>&
  {
    clear();
    clone(&node);

    data_ = node.data();

    return *this;
  }

  /// Provides access to the underlying C GObject.
  inline auto gobj() -> GNode*
  {
    return gobject_;
  }

  /// Provides access to the underlying C GObject.
  inline auto gobj() const -> const GNode*
  {
    return gobject_;
  }

  /** Inserts a NodeTree beneath the parent at the given position.
   *
   * @param position the position to place node at, with respect to its siblings
   * If position is -1, node is inserted as the last child of parent
   * @param node the NodeTree to insert
   * @return the inserted NodeTree
   */
  auto insert(int position, NodeTree<T>& node) -> NodeTree<T>&
  {
    g_node_insert(gobj(), position, node.gobj());
    return node;
  }


  /** Inserts a NodeTree beneath the parent before the given sibling.
   *
   * @param sibling the sibling NodeTree to place node before.
   * @param node the NodeTree to insert
   * @return the inserted NodeTree
   */
  auto insert_before(NodeTree<T>& sibling, NodeTree<T>& node) -> NodeTree<T>&
  {
    g_node_insert_before(gobj(), sibling.gobj(), node.gobj());
    return node;
  }


  /** Inserts a NodeTree beneath the parent after the given sibling.
   *
   * @param sibling the sibling NodeTree to place node after.
   * @param node the NodeTree to insert
   * @return the inserted NodeTree
   */
  auto insert_after(NodeTree<T>& sibling, NodeTree<T>& node) -> NodeTree<T>&
  {
    g_node_insert_after(gobj(), sibling.gobj(), node.gobj());
    return node;
  }


  /** Inserts a NodeTree as the last child.
   *
   * @param node the NodeTree to append
   * @return the new NodeTree
   */
  auto append(NodeTree<T>& node) -> NodeTree<T>&
  {
    g_node_append(gobj(), node.gobj());
    return node;
  }

  /** Inserts a NodeTree as the first child.
   *
   * @param node the NodeTree to prepend
   * @return the NodeTree
   */
  auto prepend(NodeTree<T>& node) -> NodeTree<T>&
  {
    g_node_prepend(gobj(), node.gobj());
    return node;
  }


  /** Inserts a new NodeTree at the given position.
   *
   * @param position the position to place the new NodeTree at.
   * If position is -1, the new NodeTree is inserted as the last child of parent
   * @param the_data the data for the new NodeTree
   * @return the new NodeTree
   */
  auto insert_data(int position, const T& the_data) -> NodeTree<T>*
  {
    NodeTree<T>* node = new NodeTree<T>(the_data);
    insert(position, *node);
    return node;
  }

  /** Inserts a new NodeTree before the given sibling.
   *
   * @param sibling the sibling NodeTree to place node before.
   * @param the_data the data for the new NodeTree
   * @return the new NodeTree
   */
  auto insert_data_before(NodeTree<T>& sibling, const T& the_data) -> NodeTree<T>*
  {
    NodeTree<T>* node = new NodeTree<T>(the_data);
    insert_before(sibling, *node);
    return node;
  }

  /** Inserts a new NodeTree as the last child.
   *
   * @param the_data the data for the new NodeTree
   * @return the new NodeTree
   */
  auto append_data(const T& the_data) -> NodeTree<T>*
  {
    NodeTree<T>* node = new NodeTree<T>(the_data);
    append(*node);
    return node;
  }

  /** Inserts a new NodeTree as the first child.
   *
   * @param the_data the data for the new NodeTree
   * @return the new NodeTree
   */
  auto prepend_data(const T& the_data) -> NodeTree<T>*
  {
    NodeTree<T>* node = new NodeTree<T>(the_data);
    prepend(*node);
    return node;
  }

  /** Reverses the order of the children.
   */
  void reverse_children()
  {
    g_node_reverse_children(gobj());
  }


  /** Returns a pointer to the root of the tree.
   *
   * @return A pointer to the root of the tree.
   */
  auto get_root() -> NodeTree<T>*
  {
    return wrap(g_node_get_root(gobj()));
  }

  auto get_root() const -> const NodeTree<T>*
  {
    return wrap(g_node_get_root(const_cast<GNode*>(gobj())));
  }


  // Can't use _WRAP_ENUM for a Flags-type enum in a template class.
  // gmmproc would get the bitwise operators wrong.
  /** Specifies which nodes are visited during several of the NodeTree methods,
   *  including traverse() and find().
   *
   * @ingroup glibmmEnums
   */
  enum class TraverseFlags
  {
    LEAVES = G_TRAVERSE_LEAVES, /*!< Only leaf nodes should be visited. */
    NON_LEAVES = G_TRAVERSE_NON_LEAVES, /*!< Only non-leaf nodes should be visited. */
    ALL = G_TRAVERSE_ALL, /*!< All nodes should be visited. */
    MASK = G_TRAVERSE_MASK /*!< A mask of all traverse flags. */
  };

  /** Traverses a tree starting at the current node.
   * It calls the given function for each node visited.
   * The traversal can be halted at any point by returning true from @a func.
   *
   * @param order The order in which nodes are visited.
   * @param flags Which types of children are to be visited.
   * @param max_depth The maximum depth of the traversal.
   * Nodes below this depth will not be visited.
   * If max_depth is -1 all nodes in the tree are visited.
   * If max_depth is 1, only the root is visited.
   * If max_depth is 2, the root and its children are visited. And so on.
   * @param func the slot to invoke for each visited child
   */
  void traverse(const TraverseFunc& func, TraverseType order = TraverseType::IN_ORDER, TraverseFlags flags = TraverseFlags::ALL, int max_depth = -1)
  {
    TraverseFunc func_copy = func;
    g_node_traverse(gobj(), (GTraverseType)order, (GTraverseFlags)flags, max_depth, c_callback_traverse, reinterpret_cast<gpointer>(&func_copy));
  }
  ;

  /** Calls a function for each of the children of a NodeTree.
   * Note that it doesn't descend beneath the child nodes.
   *
   * @param flags Wwhich types of children are to be visited.
   * @param func The slot to invoke for each visited node.
   */
  void foreach(const ForeachFunc& func, TraverseFlags flags = TraverseFlags::ALL)
  {
    ForeachFunc func_copy = func;
    g_node_children_foreach(gobj(), (GTraverseFlags)flags, c_callback_foreach, reinterpret_cast<gpointer>(&func_copy));
  }


  /** Finds the first child of a NodeTree with the given data.
   *
   * @param flags Which types of children are to be visited, one of TraverseFlags::ALL, TraverseFlags::LEAVES or TraverseFlags::NON_LEAVES.
   * @param the_data The data for which to search.
   * @return the found child, or <tt>nullptr</tt> if the data is not found
   */
  auto find_child(const T& the_data, TraverseFlags flags = TraverseFlags::ALL) -> NodeTree<T>*
  {
    sigc::slot<void(GNode*, const T&, GNode**)> real_slot = sigc::ptr_fun(on_compare_child);

    GNode* child = nullptr;
    using type_foreach_gnode_slot = sigc::slot<void(GNode*)>;
    type_foreach_gnode_slot bound_slot = sigc::bind(real_slot, the_data, &child);

    g_node_children_foreach(gobj(), (GTraverseFlags)flags, c_callback_foreach_compare_child, reinterpret_cast<gpointer>(&bound_slot));

    return wrap(child);
  }

  /** Finds the first child of a NodeTree with the given data.
   *
   * @param flags Which types of children are to be visited, one of TraverseFlags::ALL, TraverseFlags::LEAVES or TraverseFlags::NON_LEAVES.
   * @param the_data The data for which to search.
   * @return the found child, or <tt>nullptr</tt> if the data is not found
   */
  auto find_child(const T& the_data, TraverseFlags flags = TraverseFlags::ALL) const -> const NodeTree<T>*
  {
    return const_cast<NodeTree<T>*>(this)->find_child(flags, the_data);
  }


  /** Finds a node in a tree.
   *
   * @param order The order in which nodes are visited: TraverseType::IN_ORDER, TraverseType::PRE_ORDER, TraverseType::POST_ORDER, or TraverseType::LEVEL_ORDER
   * @param flags Which types of children are to be visited: one of TraverseFlags::ALL, TraverseFlags::LEAVES or TraverseFlags::NON_LEAVES.
   * @param the_data The data for which to search.
   * @return The found node, or <tt>nullptr</tt> if the data is not found.
   */
  auto find(const T& the_data, TraverseType order = TraverseType::IN_ORDER, TraverseFlags flags = TraverseFlags::ALL) -> NodeTree<T>*
  {
    //We use a sigc::slot for the C callback, so we can bind some extra data.
    sigc::slot<gboolean(GNode*, const T&, GNode**)> real_slot = sigc::ptr_fun(on_compare_node);
    GNode* child = nullptr;

    using type_traverse_gnode_slot = sigc::slot<gboolean(GNode*)>;
    type_traverse_gnode_slot bound_slot = sigc::bind(real_slot, the_data, &child);

    g_node_traverse(const_cast<GNode*>(gobj()), (GTraverseType)order, (GTraverseFlags)flags, -1, c_callback_traverse_compare_node, reinterpret_cast<gpointer>(&bound_slot));

    return wrap(child);
  }

  /** Finds a node in a tree.
   *
   * @param order The order in which nodes are visited.
   * @param flags Which types of children are to be visited.
   * @param the_data The data for which to search.
   * @return The found node, or <tt>nullptr</tt> if the data is not found.
   */
  auto find(const T& the_data, TraverseType order = TraverseType::IN_ORDER, TraverseFlags flags = TraverseFlags::ALL) const -> const NodeTree<T>*
  {
    return const_cast<NodeTree<T>*>(this)->find(order, flags, the_data);
  }


  /** Gets the position of the first child which contains the given data.
   *
   * @param the_data The data to find.
   * @return The index of the child which contains data, or -1 if the data is not found.
   */
  auto child_index(const T& the_data) const -> int
  {
    int n = 0;

    for(const NodeTree<T>* i = first_child();  i != nullptr; i = i->next_sibling())
    {
      if((i->data()) == the_data)
        return n;

      n++;
    }

    return -1;
  }


  /** Gets the position with respect to its siblings.
   * child must be a child of node.
   * The first child is numbered 0, the second 1, and so on.
   *
   * @param child A child
   * @return The position of @a child with respect to its siblings.
   */
  auto child_position(const NodeTree<T>& child) const -> int
  {
    return g_node_child_position(const_cast<GNode*>(gobj()), const_cast<GNode*>(child.gobj()));
  }


  /** Gets the first child.
   *
   * @return The first child, or <tt>nullptr</tt> if the node has no children.
   */
  auto first_child() -> NodeTree<T>*
  {
    return wrap(g_node_first_child(gobj()));
  }

  /** Gets the first child.
   *
   * @return The first child, or <tt>nullptr</tt> if the node has no children.
   */
  auto first_child() const -> const NodeTree<T>*
  {
    return const_cast<NodeTree<T>*>(this)->first_child();
  }

  /** Gets the last child.
   *
   * @return The last child, or <tt>nullptr</tt> if the node has no children.
   */
  auto last_child() -> NodeTree<T>*
  {
    return wrap(g_node_last_child(gobj()));
  }

  /** Gets the last child.
   *
   * @return The last child, or <tt>nullptr</tt> if the node has no children.
   */
  auto last_child() const -> const NodeTree<T>*
  {
    return const_cast<NodeTree<T>*>(this)->last_child();
  }


  /** Gets the nth child.
   *
   * @return The nth child, or <tt>nullptr</tt> if n is too large.
   */
  auto nth_child(int n) -> NodeTree<T>*
  {
    return wrap(g_node_nth_child(gobj(), n));
  }

  /** Gets the nth child.
   *
   * @return The nth child, or <tt>nullptr</tt> if n is too large.
   */
  auto nth_child(int n) const -> const NodeTree<T>*
  {
    return const_cast<NodeTree<T>*>(this)->nth_child(n);
  }


  /** Gets the first sibling
   * @return The first sibling, or <tt>nullptr</tt> if the node has no siblings.
   */
  auto first_sibling() -> NodeTree<T>*
  {
    return wrap(g_node_first_sibling(gobj()));
  }

  /** Gets the first sibling
   * @return The first sibling, or <tt>nullptr</tt> if the node has no siblings.
   */
  auto first_sibling() const -> const NodeTree<T>*
  {
    return const_cast<NodeTree<T>*>(this)->first_sibling();
  }


  /** Gets the previous sibling.
   *
   * @return The previous sibling, or <tt>nullptr</tt> if the node has no siblings.
   */
  auto prev_sibling() -> NodeTree<T>*
  {
    return wrap(g_node_prev_sibling(gobj()));
  }

  /** Gets the previous sibling.
   *
   * @return The previous sibling, or <tt>nullptr</tt> if the node has no siblings.
   */
  auto prev_sibling() const -> const NodeTree<T>*
  {
    return const_cast<NodeTree<T>*>(this)->prev_sibling();
  }

  /** Gets the next sibling
   *
   * @return The next sibling, or <tt>nullptr</tt> if the node has no siblings.
   */
  auto next_sibling() -> NodeTree<T>*
  {
    return wrap(g_node_next_sibling(gobj()));
  }

  /** Gets the next sibling
   *
   * @return The next sibling, or <tt>nullptr</tt> if the node has no siblings.
   */
  auto next_sibling() const -> const NodeTree<T>*
  {
    return const_cast<NodeTree<T>*>(this)->next_sibling();
  }

  /** Gets the last sibling.
   *
   * @return The last sibling, or <tt>nullptr</tt> if the node has no siblings.
   */
  auto last_sibling() -> NodeTree<T>*
  {
    return wrap(g_node_last_sibling(gobj()));
  }

  /** Gets the last sibling.
   *
   * @return The last sibling, or <tt>nullptr</tt> if the node has no siblings.
   */
  auto last_sibling() const -> const NodeTree<T>*
  {
    return const_cast<NodeTree<T>*>(this)->last_sibling();
  }


  /** Returns true if this is a leaf node.
   *
   * @return true if this is a leaf node.
   */
  auto is_leaf() const -> bool
  {
    return G_NODE_IS_LEAF(const_cast<GNode*>(gobj()));
  }

  /** Returns true if this is the root node.
   *
   * @return true if this is the root node.
   */
  auto is_root() const -> bool
  {
    return G_NODE_IS_ROOT(const_cast<GNode*>(gobj()));
  }

  /** Gets the depth of this node.
   * The root node has a depth of 1.
   * For the children of the root node the depth is 2. And so on.
   *
   * @return the depth of this node
   */
  auto depth() const -> guint
  {
    return g_node_depth(const_cast<GNode*>(gobj()));
  }


  /** Gets the number of nodes in a tree.
   *
   * @param flags Which types of children are to be counted: one of TraverseFlags::ALL, TraverseFlags::LEAVES or TraverseFlags::NON_LEAVES
   * @return The number of nodes in the tree.
   */
  auto node_count(TraverseFlags flags = TraverseFlags::ALL) const -> guint
  {
    return g_node_n_nodes(const_cast<GNode*>(gobj()), (GTraverseFlags)flags);
  }


  /** Gets the number children.
   *
   * @return The number of children.
   */
  auto child_count() const -> guint
  {
    return g_node_n_children(const_cast<GNode*>(gobj()));
  }


  /** Returns true if this is an ancestor of @a descendant.
   * This is true if this is the parent of @a descendant,
   * or if this is the grandparent of @a descendant etc.
   *
   * @param descendant A node.
   * @return true if this is an ancestor of descendant.
   */
  auto is_ancestor(const NodeTree<T>& descendant) const -> bool
  {
    return g_node_is_ancestor(const_cast<GNode*>(gobj()), const_cast<GNode*>(descendant.gobj()));
  }


  /** Gets the maximum height of all branches beneath this node.
   * This is the maximum distance from the node to all leaf nodes.
   * If root has no children, 1 is returned. If root has children, 2 is returned. And so on.
   *
   * @return The maximum height of all branches.
   */
  auto get_max_height() const -> guint
  {
    return g_node_max_height(const_cast<GNode*>(gobj()));
  }


  /** Unlinks a node from a tree, resulting in two separate trees.
   */
  void unlink()
  {
    g_node_unlink(gobj());
  }


#if 0 //Commented-out because people can just use the copy constructor.
  /** Recursively copies a node and it's data.
   *
   * Returns: a new node containing the copies of the data.
   */
  NodeTree<T>* copy_deep() const
  {
    //Use copy constructor instead of g_node_copy_deep to create C++ wrappers also not only the wrapped C objects.
    return new NodeTree<T>(*this);
  }
#endif


  /// Accessor for this node's data
  auto data() -> T&
  {
    return data_;
  }

  /// Accessor for this node's data
  auto data() const -> const T&
  {
    return data_;
  }

  /** Accessor for this node's parent.
   *
   * @return The node's parent.
   */
  auto parent() const -> const NodeTree<T>*
  {
    return wrap(gobj()->parent);
  }

  // Do not wrap this shallow copy function, because it is not useful:


private:

  void clear()
  {
    //Free the children (not just with g_node_destroy(), to avoid the leaking of C++ wrapper objects):
    while(NodeTree<T>* i = first_child())
      delete i;

    //Free the wrapped object (g_node_free not available)
    g_slice_free(GNode, gobject_);
    gobject_ = nullptr;
  }

  ///Create a new GNode, taking the contents of an existing node if one is specified.
  void clone(const NodeTree<T>* node = nullptr)
  {
    //Store the this pointer in the GNode so we can discover this wrapper later:
    gobject_ = g_node_new(reinterpret_cast<gpointer>(this));

    if(node)
    {
      //Prepend the copied children of @node to the constructing node.
      for(const NodeTree<T>* i = node->last_child();  i != nullptr; i = i->prev_sibling())
        prepend(*(new NodeTree<T>(*i)));
    }
  }

  /// Wrapper for invoking a TraverseFunc.
  static auto c_callback_traverse(GNode* node, gpointer slot) -> gboolean
  {
    const TraverseFunc* tf = reinterpret_cast<const TraverseFunc*>(slot);
    return (*tf)(*wrap(node));
  }

  /// Wrapper for invoking a ForeachFunc.
  static void c_callback_foreach(GNode* node, gpointer slot)
  {
    const ForeachFunc* ff = reinterpret_cast<const ForeachFunc*>(slot);
    (*ff)(*wrap(node));
  }

  /// Method for comparing a single child (Internal use).
  static void on_compare_child(GNode* node, const T& needle, GNode** result)
  {
    if((nullptr != result) && (wrap(node)->data() == needle))
    {
      *result = node;
    }
  }

  /// Wrapper for invoking a sigc::slot<void(GNode*)> (Internal use).
  static void c_callback_foreach_compare_child(GNode* node, gpointer data)
  {
    const ForeachFunc* slot = reinterpret_cast<const ForeachFunc*>(data);
    (*slot)(*wrap(node));
  }

  /// Method for comparing a single node (Internal use).
  static auto on_compare_node(GNode* node, const T& needle, GNode** result) -> gboolean
  {
    if(wrap(node)->data() == needle)
    {
      *result = node;
      return TRUE;
    }
    return FALSE;
  }

  /// Wrapper for invoking a sigc::slot<gboolean(GNode*)> (Internal use).
  static auto c_callback_traverse_compare_node(GNode* node, gpointer data) -> gboolean
  {
    const TraverseFunc* slot = reinterpret_cast<const TraverseFunc*>(data);
    return (*slot)(*wrap(node));
  }


  GNode* gobject_;
  T data_;


};

} // namespace Glib


#endif /* _GLIBMM_NODETREE_H */

