#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Diagnosis
{
    string name;
    string treatment;
};

class ExpertSystem
{
private:
    map<string, Diagnosis> knowledgeBase;

public:
    ExpertSystem()
    {
        // Initialize the knowledge base with more sample data
        knowledgeBase["headache"] = {"Migraine", "Painkillers and rest, Take a power nape"};
        knowledgeBase["fever"] = {"Flu", "Antiviral medication and rest"};
        knowledgeBase["cough"] = {"Common Cold", "Rest and over-the-counter cold medications"};
        knowledgeBase["stomachache"] = {"Indigestion", "Antacids and avoiding spicy foods"};
        knowledgeBase["rash"] = {"Allergic Reaction", "Antihistamines and avoiding allergens"};
        knowledgeBase["sore_throat"] = {"Strep Throat", "Antibiotics and pain relievers"};
        knowledgeBase["diarrhea"] = {"Food Poisoning", "Hydration and over-the-counter medications"};
        knowledgeBase["chest_pain"] = {"Heart Attack", "Emergency medical attention"};
        knowledgeBase["shortness_of_breath"] = {"Asthma", "Bronchodilators and avoiding triggers"};
        knowledgeBase["joint_pain"] = {"Arthritis", "Anti-inflammatory medications and physical therapy"};
        // Add more diseases and treatments here
    }

    Diagnosis diagnose(const vector<string> &symptoms)
    {
        // Check if any of the symptoms match the knowledge base
        for (const auto &symptom : symptoms)
        {
            if (knowledgeBase.find(symptom) != knowledgeBase.end())
            {
                return knowledgeBase[symptom];
            }
        }
        // If no matching symptoms are found, return "Unknown" diagnosis
        return {"Unknown", "Further evaluation needed"};
    }
};

int main()
{
    ExpertSystem expertSystem;
    vector<string> symptoms;
    cout << "Enter symptoms (one per line, enter 'done' when finished):" << endl;
    string symptom;
    while (true)
    {
        cout << "Enter the symptom:";
        cin >> symptom;
        if (symptom == "done")
        {
            break;
        }
        symptoms.push_back(symptom);
    }

    Diagnosis diagnosis = expertSystem.diagnose(symptoms);

    cout << "\nDiagnosis: " << diagnosis.name << endl;
    cout << "Treatment: " << diagnosis.treatment << endl;
    return 0;
}
