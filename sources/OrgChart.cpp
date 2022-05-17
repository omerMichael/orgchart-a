#include "OrgChart.hpp"

namespace ariel {

	TreeIterator::TreeIterator(Tree* node): node(node) {}

	std::string& TreeIterator::operator*() {
		return node->value;
	}

	std::string* TreeIterator::operator->() {
		return &node->value;
	}

	OrgChart::LevelOrderIterator::LevelOrderIterator(Tree* node): TreeIterator::TreeIterator(node) {}

	OrgChart::LevelOrderIterator& OrgChart::LevelOrderIterator::operator++() {
		return *this;
	}

	bool OrgChart::LevelOrderIterator::operator==(OrgChart::LevelOrderIterator other) const {
		return node->value.compare(other.node->value) == 0;
	}

	bool OrgChart::LevelOrderIterator::operator!=(OrgChart::LevelOrderIterator other) const {
		return node->value.compare(other.node->value) != 0;
	}

	OrgChart::ReverseOrderIterator& OrgChart::ReverseOrderIterator::operator++() {
		return *this;
	}

	bool OrgChart::ReverseOrderIterator::operator==(OrgChart::ReverseOrderIterator other) const {
		return node->value.compare(other.node->value) == 0;
	}

	bool OrgChart::ReverseOrderIterator::operator!=(OrgChart::ReverseOrderIterator other) const {
		return node->value.compare(other.node->value) != 0;
	}

	OrgChart::PreorderIterator& OrgChart::PreorderIterator::operator++() {
		return *this;
	}

	bool OrgChart::PreorderIterator::operator==(OrgChart::PreorderIterator other) const {
		return node->value.compare(other.node->value) == 0;
	}

	bool OrgChart::PreorderIterator::operator!=(OrgChart::PreorderIterator other) const {
		return node->value.compare(other.node->value) != 0;
	}

	OrgChart::ReverseOrderIterator::ReverseOrderIterator(Tree* node): TreeIterator::TreeIterator(node) {}

	OrgChart::PreorderIterator::PreorderIterator(Tree* node): TreeIterator::TreeIterator(node) {}

	OrgChart::OrgChart() {
		root.value = "";
	}

	OrgChart& OrgChart::add_root(std::string root) {
		return *this;
	}

	OrgChart& OrgChart::add_sub(std::string parent, std::string child) {
		return *this;
	}

	std::ostream& operator<<(std::ostream& output, const OrgChart& me) {
		return output;
	}

	OrgChart::LevelOrderIterator OrgChart::begin() {
		return begin_level_order();
	}

	OrgChart::LevelOrderIterator OrgChart::end() {
		return end_level_order();
	}
	
	OrgChart::LevelOrderIterator OrgChart::begin_level_order() {
		return OrgChart::LevelOrderIterator(&root);
	}

	OrgChart::LevelOrderIterator OrgChart::end_level_order() {
		return OrgChart::LevelOrderIterator(&root);
	}

	OrgChart::ReverseOrderIterator OrgChart::begin_reverse_order() {
		return OrgChart::ReverseOrderIterator(&root);
	}

	OrgChart::ReverseOrderIterator OrgChart::reverse_order() {
		return OrgChart::ReverseOrderIterator(&root);
	}

	OrgChart::PreorderIterator OrgChart::begin_preorder() {
		return OrgChart::PreorderIterator(&root);
	}

	OrgChart::PreorderIterator OrgChart::end_preorder() {
		return OrgChart::PreorderIterator(&root);
	}
}
