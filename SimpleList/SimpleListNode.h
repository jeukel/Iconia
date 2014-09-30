#ifndef SIMPLELISTNODE_H
#define SIMPLELISTNODE_H
#include "SimpleList/interfaceNode.h"
/*!
 * \brief The SimpleListNode class. A simple list node is the corresponding node to the data structure
 * "simple linked list".
 */
template <typename K>
class SimpleListNode: public interfaceNode<K> {
public:
    /*!
     * \brief SimpleListNode is the constructor
     */
    SimpleListNode();
    virtual ~SimpleListNode();
    /*!
     * \brief setElement function that sets the element of the node
     * \param pElement the element that is going to be set
     */
    void setElement(K pElement);
    /*!
     * \brief getElement
     * \return the element that contains the node.
     */
    K* getElement();
    /*!
     * \brief setNext
     * \param pNextNode
     */
    void setNext(SimpleListNode<K>* pNextNode);
    /*!
     * \brief getNext
     * \return
     */
    SimpleListNode<K>* getNext();
    /*!
     * \brief setPrevious
     * \param pPreviousNode
     */
    void setPrevious(SimpleListNode<K>* pPreviousNode);
    /*!
     * \brief getPrevious
     * \return
     */
    SimpleListNode<K>* getPrevious();
private:
    /*!
     * \brief _next this is a pointer to a node that is said is next to the current one
     */

    interfaceNode<K>* _next ;
    /*!
     * \brief _previous pointer to the node is said is before the current one
     */
    interfaceNode<K>* _previous;
};

/*!
 * Simple list node constructor implementing
 */
template <typename K>
SimpleListNode<K>::SimpleListNode() {
    this->_next = 0;
    this->_element = 0;
}

/*!
 * Template::Simple list node destructor.
 */
template <typename K>
SimpleListNode<K>::~SimpleListNode(){
}

/*!
 * Template::Set element on a node.
 */
template <typename K>
void SimpleListNode<K>::setElement(K pElement){
    this->_element = pElement;
}

/*!
 * Template::Get Element
 */
template <typename K>
K* SimpleListNode<K>::getElement(){
    return &(this->_element);
}

/*!
 * Template::Set next
 */
template <typename K>
void SimpleListNode<K>::setNext(SimpleListNode<K> *pNextNode){
    this->_next = pNextNode;
}

/*!
 * Template::Get Next
 */
template <typename K>
SimpleListNode<K>* SimpleListNode<K>::getNext(){
    return (SimpleListNode<K>*)this->_next;
}

#endif // SIMPLELISTNODE_H
