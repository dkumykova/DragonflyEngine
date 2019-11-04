#include <string>
#ifndef __MANAGER_H__
#define __MANAGER_H__
namespace df {
	class Manager {
	private:
		std::string m_type;
		bool m_is_started;

	protected:
		void setType(std::string type);

	public:
		Manager();
		virtual ~Manager();

		std::string getType() const;

		virtual int startUp();

		virtual void shutDown();

		bool isStarted() const;
	};
}
#endif
