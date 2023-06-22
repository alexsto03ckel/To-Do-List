#pragma once
#include<wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

private:
	void createControls();
	void BindEventHandlers();

	void OnAddButtonClicked(wxCommandEvent& event);
	void OnInputEnter(wxCommandEvent& event);
//	void OnListKeyDown(wxKeyEvent& event);
	void OnClearButtonClicked(wxCommandEvent& event);
	void OnClearAll(wxCommandEvent& event);
	void OnWindowClosed(wxCloseEvent& event);
	void AddSavedTasks();

	void AddTaskFromInput();
	void DeleteSelectedTask();
//	void MoveSelectedTask(int offset);
//	void SwapTasks(int i, int j);

	wxPanel* panel;
	wxStaticText* headlineText; //create the head line
	wxTextCtrl* inputField; //enter the task
	wxButton* addButton; //add task
	wxCheckListBox* checkListBox; //show the tasks
	wxButton* clearButton; //clear the tasks;
	wxButton* clearAllTasks;
};

