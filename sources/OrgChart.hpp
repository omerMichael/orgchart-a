#include <iterator>
#include <vector>

namespace ariel {

	struct Tree {
		std::string value;
		std::vector<Tree*> children;
	};

	class TreeIterator: public std::iterator<std::input_iterator_tag, Tree*> {
		public:
			virtual ~TreeIterator() = default;

			explicit TreeIterator(Tree* node);

			virtual TreeIterator& operator++() = 0;

			std::string& operator*();

			std::string* operator->();

		protected:
			Tree* node;
	};


	class OrgChart {
		public:
			class LevelOrderIterator;

			class ReverseOrderIterator;

			class PreorderIterator;

			OrgChart();

			/**
			 * @brief Add a root level rank, will be the head of the 
			 * 		  Chart
			 *	
			 * @param root - The level that will be the head of the 
			 * 				 Chart.
			 * */
			OrgChart& add_root(std::string root);

			/**
			 * @brief Add a new child level under a given parent level
			 *
			 * @param parent - the Parent level under which the child will be placed.
			 * 				   NOTE: Must exist already in the Chart
			 *
			 * @param child - the new child level
			 * */
			OrgChart& add_sub(std::string parent, std::string child);

			friend std::ostream& operator<<(std::ostream& outout, const OrgChart& me);

			LevelOrderIterator begin();

			LevelOrderIterator end();

			LevelOrderIterator begin_level_order();

			LevelOrderIterator end_level_order();

			ReverseOrderIterator begin_reverse_order();

			ReverseOrderIterator reverse_order();

			PreorderIterator begin_preorder();

			PreorderIterator end_preorder();

			class LevelOrderIterator: public TreeIterator {
				public:
					explicit LevelOrderIterator(Tree* node);

					LevelOrderIterator& operator++() override;

					bool operator==(LevelOrderIterator other) const;

					bool operator!=(LevelOrderIterator other) const;
			};

			class ReverseOrderIterator: public TreeIterator {
				public:
					explicit ReverseOrderIterator(Tree* node);

					virtual ReverseOrderIterator& operator++() override;

					bool operator==(ReverseOrderIterator other) const;
					
					bool operator!=(ReverseOrderIterator other) const;
			};

			class PreorderIterator: public TreeIterator {
				public:
					explicit PreorderIterator(Tree* node);

					virtual PreorderIterator& operator++() override;

					bool operator==(PreorderIterator other) const;

					bool operator!=(PreorderIterator other) const;
			};

		private:
			Tree root;
	};
}
