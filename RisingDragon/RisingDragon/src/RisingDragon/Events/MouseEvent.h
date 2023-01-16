#pragma once
#include "rdpch.h"
#include "Event.h"

namespace RisingDragon
{
	
	class RD_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float mouseX, float mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}

		inline float GetMouseX() { return this->m_MouseX; }
		inline float GetMouseY() { return this->m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_MouseX, m_MouseY;
	};

	class RD_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffSet, float yOffSet)
			:m_xOffSet(xOffSet), m_yOffSet(yOffSet) {}

		inline float GetXOffSet() { return this->m_xOffSet; }
		inline float GetYOffSet() { return this->m_yOffSet; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_xOffSet << ", " << m_yOffSet;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_xOffSet, m_yOffSet;
	};

	class RD_API MouseButtonEvent : public Event
	{
	public:
		inline int GetButtonCode() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)
	protected:
		MouseButtonEvent(int mouseButtonCode)
			: m_Button(mouseButtonCode) {}

		int m_Button;
	};

	class RD_API MouseButtonPressedEvent: public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << this->m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class RD_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << this->m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}