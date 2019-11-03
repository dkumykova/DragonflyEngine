//used for timing for the game loop

namespace df {
	class Clock {

	private:
		long int m_previous_time; //previous time delta() called, microsec

	public:
		Clock(); //set previous time = current time


		//return time elapsed since delta() last called, -1 if error
		//reset previous time
		//microsec
		long int delta(); 

		//return elapsed time since delta() last called, -1 if error
		//does NOT reset previous time
		//microsec
		long int split() const;
	};
}
