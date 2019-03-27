#ifndef ALGOSTRUCT_TREELCRS_H
#define ALGOSTRUCT_TREELCRS_H

/*
 * Tree Left-Child Right-Sibling. Only constructive, not changeable.
 */
namespace algostruct {
    template<typename Data>
    class VertexLCRS {
        Data data_;
        VertexLCRS *parent = nullptr;
        VertexLCRS *child = nullptr;
        VertexLCRS *sibling = nullptr;
    public:
        explicit VertexLCRS(Data data);
        class Iterator {
            VertexLCRS *current_;
            bool tryUp() {
                while (current_->parent) {
                    current_ = current_->parent;
                    if (current_->sibling) {
                        current_ = current_->sibling;
                        return true;
                    }
                }
                return false;
            }
        public:
            explicit Iterator(VertexLCRS* vertex) : current_(vertex) {
            }
            bool operator==(const Iterator& rhs) {
                return current_ == rhs.current_;
            }
            bool operator!=(const Iterator& rhs) {
                return !(*this == rhs);
            }
            Data &operator*() {
                return current_->data_;
            }
            Iterator& operator++() {
                if (current_->child) {
                    current_ = current_->child;
                    return *this;
                } else if (current_->sibling) {
                    current_ = current_->sibling;
                    return *this;
                } else {
                    if (!tryUp()) {
                        current_ = nullptr;
                    }
                    return *this;
                }
            }
        };
        const Data& getData() const;
        void linkAsChild(VertexLCRS *vertex);
        void linkAsSibling(VertexLCRS *vertex);
        void linkAsParent(VertexLCRS *vertex);
        Iterator begin() {
            return Iterator(this);
        }
        Iterator end() {
            return Iterator(nullptr);
        }
    };
    template<typename Data>
    VertexLCRS<Data>::VertexLCRS(Data data) : data_(data) {
    }
    template<typename Data>
    const Data& VertexLCRS<Data>::getData() const {
        return data_;
    }
    template<typename Data>
    void VertexLCRS<Data>::linkAsChild(VertexLCRS *vertex) {
        vertex->child = this;
        parent = vertex;
    }
    template<typename Data>
    void VertexLCRS<Data>::linkAsSibling(VertexLCRS *vertex) {
        vertex->sibling = this;
        parent = vertex->parent;

    }
    template<typename Data>
    void VertexLCRS<Data>::linkAsParent(VertexLCRS *vertex) {
        child = vertex;
        vertex->parent = this;
    }
}

#endif //ALGOSTRUCT_TREELCRS_H
