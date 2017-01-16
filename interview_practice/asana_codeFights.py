import time
# start_time = time.time()
# main()
# print("--- %s seconds ---" % (time.time() - start_time))

def smartAssigning(names, statuses, projects, tasks):
    filtered_names, filtered_projects, filtered_tasks = [], [], []
    for i,status in enumerate(statuses):
        if status == False:
            filtered_names.append(names[i])
            filtered_projects.append(projects[i])
            filtered_tasks.append(tasks[i])

    taskDict = {}
    if filtered_names == []: return "ERROR all on vacation"
    # print filtered_names
    # print filtered_projects
    # print filtered_tasks

    for i,task in enumerate(filtered_tasks):
        if task not in taskDict:
            taskDict[task] = []
        taskDict[task].append(filtered_names[i])

    filtered_tasks.sort()
    namesList = taskDict[filtered_tasks[0]]
    print namesList
    if len(namesList) == 1: return namesList[0]
    minProj, resName = filtered_projects[0], filtered_names[0]
    for i,name in enumerate(filtered_names):
        if name in namesList:
            if filtered_projects[i] < minProj:
                minProj = filtered_projects[i]
                resName = filtered_names[i]
    return resName

start_time = time.time()
names = ["John", "Watson"]
statuses = [False, False]
projects = [1, 0]
tasks = [2, 2]
print smartAssigning(names, statuses, projects, tasks)
print("--- %s seconds ---" % (time.time() - start_time))
